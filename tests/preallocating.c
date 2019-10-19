#include "../walloc.h"

int main() {
    prewalloc(256); // preallocate 255 bytes. will make subsequent allocations faster.
    char *myMemory = walloc(20); // takes significantly less time since memory does not need to be requested from the OS.
    wfree(myMemory); // frees the memory, and saves it for later allocations
}