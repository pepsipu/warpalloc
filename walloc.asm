%macro sbrk 1
    mov ebx, %1
    add ebx, [ptr_bss_end]
    mov eax, 0x2d
    int 0x80
    add dword [ptr_bss_end], %1
%endmacro

%macro get_free_space 1
     mov %1, [ptr_bss_end] ; get end of program break
     sub %1, [ptr_wilderness] ; total space - used space = available space
%endmacro

%macro link_free 1
    mov ebx, [fbin]
    mov [%1 - 4], ebx
    mov [fbin], %1
    ;newchunk->fd = fbin->fd
    ;fbin->fd = newchunk
%endmacro

%macro unlink_free 2
    mov ecx, [%1 - 4]
    mov dword [%2 - 4], ecx
%endmacro
section .bss
    ptr_wilderness: resb 4 ; pointer to free memory, 4 bytes
    ptr_bss_end: resb 4 ; pointer to end of bss, 4 bytes
    fbin: resb 4 ; free bin stores freed chunks with single linked list starting at fd_ptr, 4 bytes
section .text

    global walloc
    global wfree
    global prewalloc

    walloc:
        push ebx

        ;--assert_prewalloced--
        mov edx, [ptr_wilderness]
        test edx, edx ; check if edx is zero, ensure the wilderness pointer is set
        je .error
        ;----------------------

        ;--store_req_space--
        mov esi, [esp + 8]
        add esi, 8 ; add space for metadata to do size check
        ;-------------------

        ;--check_free_chunks--
        mov eax, [fbin]
        .size_check_loop:
        test eax, eax
        je .check_wilderness ; if end of free chunks, then use space of wilderness
        cmp esi, [eax - 8]
        jg .no_fit
        mov dword [eax - 8], esi
        unlink_free eax, ebx
        jmp .return
        .no_fit:
        mov ebx, eax ; save prev linked chunk in case of unlink
        mov eax, [eax - 4] ; move fd pointer of current chunk into eax
        jmp .size_check_loop
        ;---------------------

        ;--use-wilderness--
        .check_wilderness:
        get_free_space eax
        cmp eax, esi ; compare available space to requested space
        jge .set_meta ; if available space is bigger than requested, set metadata
        sub esi, eax ; remove excess space
        sbrk esi
        ;------------------

        ;--write_size--
        .set_meta:
        mov dword [edx], esi ; set size at pointer to wilderness or free chunk
        add [ptr_wilderness], esi ; increase pointer to wilderness by new chunk size
        ;--------------

        ;--set_return_value--
        mov eax, edx ; move edx
        add eax, 8
        ;--------------------

        .return:
        pop ebx
        ret

        .error:
        xor eax, eax
        jmp .return

    wfree:
        push ebx
        mov eax, [esp + 8]
        link_free eax
        pop ebx
        ret

    prewalloc:
        push ebx
        mov esi, [esp + 8]
        mov dword [ptr_wilderness], fbin + 8
        mov dword [ptr_bss_end], fbin + 8
        sbrk esi ; increment break by requested size
        pop ebx
        ret
