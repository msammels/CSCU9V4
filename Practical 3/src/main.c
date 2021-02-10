/**
 * CSCU9V4 - Practical 3
 * Michael Sammels
 * main.c
 * 05.02.2021
 **/

#include <stdio.h>

void addFrac(int num1, int denom1, int num2, int denom2);
void multiFrac(int num1, int denom1, int num2, int denom2);

int main() {
    int num1 = 0, denom1 = 0, num2 = 0, denom2 = 0;
    char choice = '\0';

    /* User input */
    printf("Do you want to add or multiply a fraction?\nEnter 'a' for add or 'm' for multiply:\t");
    scanf(" %c", &choice);

    printf("Enter first fraction:\t");
    scanf("%d /%d", &num1, &denom1);

    printf("Enter second fraction:\t");
    scanf("%d /%d", &num2, &denom2);

    /* Check to see if you want to add or multiply */
    if (choice == 'a') {
        addFrac(num1, denom1, num2, denom2); /* Add fraction */
    } else if (choice == 'm') {
        multiFrac(num1, denom1, num2, denom2); /* Multiply fraction */
    }

    return 0;
}

void addFrac(int num1, int denom1, int num2, int denom2) {
    int result_num, result_denom, cd = 0;
    float fracNumValue;
    result_num = num1 * denom2 + num2 * denom1; /* Numerator */
    result_denom = denom1 * denom2; /* Denominator */

    /* Find common denominator */
    for (int i = 1; i <= result_num && i <= result_denom; ++i) {
        if (result_num % i == 0 && result_denom % i == 0) {
            cd = i;
        }
    }

    result_num = result_num / cd;
    result_denom = result_denom / cd;
    fracNumValue = (result_num + 0.0) / result_denom;

    printf("The sum is %d/%d which is %.3f\n", result_num, result_denom, fracNumValue);
}

void multiFrac(int num1, int denom1, int num2, int denom2) {
    int result_num, result_denom, cd = 0;
    float fracNumValue;
    result_num = num1 * num2; /* Numerator */
    result_denom = denom1 * denom2; /* Denominator */

    /* Find common denominator */
    for (int j = 1; j <= result_num && j <= result_denom; ++j) {
        if (result_num % j == 0 && result_denom % j == 0) {
            cd = j;
        }
    }

    result_num = result_num / cd;
    result_denom = result_denom / cd;
    fracNumValue = (result_num + 0.0) / result_denom;

    printf("The multiplication result is %d/%d which is %.3f\n", result_num, result_denom, fracNumValue);
}
