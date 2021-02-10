/**
 * CSCU9V4 - Practical 6
 * Michael Sammels
 * pointers.c
 * 12.03.2021
 **/

#include <stdio.h>

int main(void) {
    int x = 42, y = 50, temp;
    int *pointer1 = &x, *pointer2 = &y;

    temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;

    printf("Pointer 1: %d", *pointer1);
    printf("\nPointer 2: %d\n", *pointer2);

    return 0;
}

