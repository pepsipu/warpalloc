# warpalloc
[![GitHub](https://img.shields.io/github/license/pepsipu/warpalloc.svg?style=for-the-badge)](https://github.com/pepsipu/warpalloc/blob/master/LICENSE.md)

Warpalloc was written in Assembly in order to bid farewell to "C clutter". Warpalloc does not use stack variables or setup the stack to optimize the code. Warpalloc also does not classify different chunks (ie fastbins, smallbins, etc) for the sake of saving clock cycles. This does not make it great for large programs that rapidly free and request more memory. In short, don't use warpalloc to make games. Warpalloc uses a new method of attaining memory called "preallocating". Preallocating requests memory from the operating system at the start of the program to save time during the program's functional execution. **YOU MUST PREALLOCATE SOMETHING. IF YOU CANNOT ESTIMATE, PREALLOCATE 0.** Warpalloc currently works with Assembly, C, and C++.

Warpalloc does not replace ptmalloc. Warpalloc only outclasses ptmalloc in smaller programs because ptmalloc has many complicated and intricate systems, that in the long run, are faster. In contrast to smaller programs, warpalloc performs better because it has one bin and no complicated heuristics.

Warpalloc is similar to ptmalloc, which you may know as "malloc", but much faster for smaller programs. In fact, warpalloc performs about *300 times* faster than ptalloc when given 25 allocations.

![graph](https://i.imgur.com/p4gdW4D.png)

It's likely ptmalloc will perform
You can test it yourself by running "benchmark.py".

### Sounds cool? How do I use it?
Using Warpalloc is amazingly simple. Simply link the object file with your source file. For example, you can do this with gcc like so.

`gcc -m32 walloc.o main.c -no-pie`

Walloc.o can get obtained in the build directory of the project, or by compiling the library with NASM.

If you'd like your IDE to recognize you are using external functions from a static library, you can either include warpalloc header file (walloc.h) or write the following at the top of your code.

```c
extern void* walloc(int size);
extern void prewalloc(int size);
extern void wfree(void *ptr);
```

Know that you *MUST* preallocating something, even if the preallocation is 0. It doesn't matter what you preallocate, since once the preallocated area ends, it will simply request more from the operating system, which can cost you time. You must preallocate before allocating or freeing.
