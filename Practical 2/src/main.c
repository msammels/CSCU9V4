/**
 * CSCU9V4 - Practical 2
 * Michael Sammels
 * main.c
 * 02.02.2021
 **/

#include <stdio.h>
#include <math.h>

int main() {
    int num, num_copy, count = 0;

    printf("Enter an integer:\t");
    scanf("%d", &num);

    /* Count how many digits are in the number. For example 3 for 123.
     * Divide (integer division) by 10 until you get to 0 */
    num_copy = num;

    while (num_copy) {
        num_copy = num_copy / 10;
        count++;
    }

    num_copy = num; /* Save the original number */

    printf("Digits of the given number are:\t");

    /* Divide (integer division) by 10 ^ (count - 1) to get the count-th left digit. For example 23/100 = 1
     * Get the remainder after the division. For example: 123 % 100 = 23
     * Cycle */
    int x;

    while (count) {
        count--;
        x = (int) pow(10, count);

        printf("%d\t", (num_copy / x));

        num_copy = num_copy % x;
    }
}
