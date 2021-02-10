/**
 * CSCU9V4 - Practical 6
 * Michael Sammels
 * main.c
 * 12.03.2021
 **/

#include <stdio.h>
#define N 5

void sum_average(int *array, int array_size, int *total, int *average) {
    int *pointer;
    pointer = array;

    for (int i = 0; i < array_size; ++i) {
        *total += *pointer++;
    }

    *average = *total / array_size;
}

int main(void) {
    int b[N], I , sum = 0, average = 0;

    printf("Enter %d numbers:\t", N);

    for (I = 0; I < N; ++I) {
        scanf("%d", &b[I]);
    }

    sum_average(b, N, &sum, &average);

    printf("\nSum: \t\t%d", sum);
    printf("\nAverage: \t%d\n", average);
}

