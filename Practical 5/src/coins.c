/**
 * CSCU9V4 - Practical 5
 * Michael Sammels
 * coins.c
 * 17.02.2021
 **/

#include <stdio.h>

#define STRING 20

int notes[] = {20, 10, 5, 1}, amount, number_of_notes, reduced_amount;
char values[(sizeof(notes) / sizeof(notes[0]))][STRING];

void amountCalculation() {
    printf("Enter a pound amount: £");
    scanf("%d", &amount);

    reduced_amount = amount;

    for (int i = 0; i < sizeof(notes) / sizeof(notes[0]); ++i) {
        number_of_notes = reduced_amount / notes[i];
        reduced_amount = reduced_amount - (number_of_notes * notes[i]);
        sprintf(values[i], "£%d notes: %d", notes[i], number_of_notes);
    }
}

int main(void) {
    /* Run the calculation */
    amountCalculation();

    for (int i =  0; i < (sizeof(values) / sizeof(values[0])); ++i) {
        printf("\n%s", values[i]);
    }

    printf("\n");   /* Blank line */

    return 0;
}