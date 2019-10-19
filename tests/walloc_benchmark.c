#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../walloc.h"

int main() {
    prewalloc(800); // preallocate 255 bytes. will make subsequent allocations faster. Done at the start of the program.
    int startTime = clock();

    char *myMemory = walloc(20); // takes significantly less time since memory does not need to be requested from the OS.
    wfree(myMemory); // frees the memory, and saves it for later allocations
    char *myMemory2 = walloc(10);
    wfree(myMemory2);
    char *myMemory3 = walloc(90); // takes significantly less time since memory does not need to be requested from the OS.
    char *myMemory4 = walloc(70);
    wfree(myMemory3);
    char *myMemory5 = walloc(20);
    wfree(myMemory4);
    char *myMemory6 = walloc(40);
    char *myMemory7 = walloc(20);
    wfree(myMemory5);
    wfree(myMemory7);
    char *myMemory8 = walloc(40);
    char *myMemory9 = walloc(20);
    wfree(myMemory9);
    wfree(myMemory8);
    wfree(myMemory6);
    char *myMemory10 = walloc(40);
    char *myMemory11 = walloc(20);
    wfree(myMemory10);
    wfree(myMemory11);
    char *myMemory12 = walloc(40);
    char *myMemory13 = walloc(20);
    wfree(myMemory13);
    wfree(myMemory12);

    char *myMemoryz = walloc(20); // takes significantly less time since memory does not need to be requested from the OS.
    wfree(myMemoryz); // frees the memory, and saves it for later allocations
    char *myMemoryz2 = walloc(10);
    wfree(myMemoryz2);
    char *myMemoryz3 = walloc(90); // takes significantly less time since memory does not need to be requested from the OS.
    char *myMemoryz4 = walloc(70);
    wfree(myMemoryz3);
    char *myMemoryz5 = walloc(20);
    wfree(myMemoryz4);
    char *myMemoryz6 = walloc(40);
    char *myMemoryz7 = walloc(20);
    wfree(myMemoryz5);
    wfree(myMemoryz7);
    char *myMemoryz8 = walloc(40);
    char *myMemoryz9 = walloc(20);
    wfree(myMemoryz9);
    wfree(myMemoryz8);
    wfree(myMemoryz6);
    char *myMemoryz10 = walloc(40);
    char *myMemoryz11 = walloc(20);
    wfree(myMemoryz10);
    wfree(myMemoryz11);
    char *myMemoryz12 = walloc(40);
    char *myMemoryz13 = walloc(20);
    wfree(myMemoryz13);
    wfree(myMemoryz12);

    int endTime = clock();
    printf("%d", endTime - startTime);
}