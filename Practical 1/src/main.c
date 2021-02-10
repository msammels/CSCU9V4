/**
 * CSCU9V4 - Practical 1
 * Michael Sammels
 * main.c
 * 01.02.2021
 **/

#include <stdio.h>

int main(void) {
    printf("Square numbers:\n");

    /* Loop through the numbers from 1 to 10 */
    for (int i = 1; i <= 10; i++) {
        /* Print the square numbers */
        printf("%d x %d = %d\n", i, i, i * i);
    }

    printf("Multiplication Times Table:\nx\n");

    /* Loop through the numbers from 1 to 10 */
    for (int i = 1; i <= 10; i++) {
        printf("\t");

        /* Loop through the numbers from 1 to 10 */
        for (int j = 1; j <= 10; j++) {
            /* Some fancy colour correction */
            if (i == j) {
                printf("\033[92m");
            } else {
                printf("\033[97m");
            }

            /* Print the times table */
            printf("%d\t", i * j);
        }

        printf("\n");
    }

    return 0;
}
