/**
 * CSCU9V4 - Practical 5
 * Michael Sammels
 * main.c
 * 17.02.2021
 **/

#include <stdio.h>

#define N 10

/* Declare functions here */
int max(int arr[], int size) {
    int max = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int min(int arr[], int size) {
    int min = size;

    for (int i = 0; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int main(void) {
    int arraySize, i, big, small;

    printf("How many numbers: ");
    scanf("%d", &arraySize);

    int b[arraySize];

    printf("Enter %d numbers: ", arraySize);

    for (i = 0; i < arraySize; i++) {
        scanf("%d", &b[i]);
    }

    printf("Largest: %d\n", max(b, arraySize));         /* Function to implement */
    printf("Smallest: %d\n", min(b, arraySize));        /* Function to implement */

    return 0;
}
