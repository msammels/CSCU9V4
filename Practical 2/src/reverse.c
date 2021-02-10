/**
 * CSCU9V4 - Practical 2
 * Michael Sammels
 * reverse.c
 * 02.02.2021
 **/

#include <stdio.h>

int main() {
    int n, remainder, rev = 0;

    printf("Please enter an integer to reverse:\t");
    scanf("%d", &n);

    /* While there are still numbers to go */
    while (n != 0) {
        remainder = n % 10; /* This takes the input mod 10 */
        
        /* Here we want to take the number, times it by 10 and add the remainder
         Upon doing so, we have the reverse.
         */
        rev = rev * 10 + remainder;
        n /= 10; /* Divide it by 10 */
    }

    printf("Reversed number:\t%d\n", rev);

    return 0;
}
