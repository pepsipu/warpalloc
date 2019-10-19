#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "../walloc.h"

int main() {
    int startTime = clock();
    char *myMemory = malloc(20); // takes significantly less time since memory does not need to be requested from the OS.
    free(myMemory); // frees the memory, and saves it for later allocations
    char *myMemory2 = malloc(10);
    free(myMemory2);
    char *myMemory3 = malloc(90); // takes significantly less time since memory does not need to be requested from the OS.
    char *myMemory4 = malloc(70);
    free(myMemory3);
    char *myMemory5 = malloc(20);
    free(myMemory4);
    char *myMemory6 = malloc(40);
    char *myMemory7 = malloc(20);
    free(myMemory5);
    free(myMemory7);
    char *myMemory8 = malloc(40);
    char *myMemory9 = malloc(20);
    free(myMemory9);
    free(myMemory8);
    free(myMemory6);
    char *myMemory10 = malloc(40);
    char *myMemory11 = malloc(20);
    free(myMemory10);
    free(myMemory11);
    char *myMemory12 = malloc(40);
    char *myMemory13 = malloc(20);
    free(myMemory13);
    free(myMemory12);

    char *myMemoryz = malloc(20); // takes significantly less time since memory does not need to be requested from the OS.
    free(myMemoryz); // frees the memory, and saves it for later allocations
    char *myMemoryz2 = malloc(10);
    free(myMemoryz2);
    char *myMemoryz3 = malloc(90); // takes significantly less time since memory does not need to be requested from the OS.
    char *myMemoryz4 = malloc(70);
    free(myMemoryz3);
    char *myMemoryz5 = malloc(20);
    free(myMemoryz4);
    char *myMemoryz6 = malloc(40);
    char *myMemoryz7 = malloc(20);
    free(myMemoryz5);
    free(myMemoryz7);
    char *myMemoryz8 = malloc(40);
    char *myMemoryz9 = malloc(20);
    free(myMemoryz9);
    free(myMemoryz8);
    free(myMemoryz6);
    char *myMemoryz10 = malloc(40);
    char *myMemoryz11 = malloc(20);
    free(myMemoryz10);
    free(myMemoryz11);
    char *myMemoryz12 = malloc(40);
    char *myMemoryz13 = malloc(20);
    free(myMemoryz13);
    free(myMemoryz12);

    int endTime = clock();

    printf("%d", endTime - startTime);
}