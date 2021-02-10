/**
 * CSCU9V4 - Practical 4
 * Michael Sammels
 * main.c
 * 15.02.2021
 **/

#include <stdbool.h>    /* C99 only */
#include <stdio.h>
#include <ctype.h>

#define BOARD_SIZE 8

int main(void) {
    int digit_seen[10] = {0};
    int digit;
    long n;
    bool flag;
    bool alternate = false;

    char board[BOARD_SIZE][BOARD_SIZE], pieces[8] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};

    do {
        printf("Enter a number: ");
        scanf("%ld", &n);   /* Not '1' but lower-case L! */
    } while (n <= 0);

    while (n > 0) {
        digit = n % 10;
        digit_seen[digit]++;
        n /= 10;
    }

    /* Checkpoint 1 */
    printf("\n");
    for (int i = 0; i < sizeof(digit_seen) / sizeof(digit_seen[0]); ++i) {
        if (digit_seen[i] >= 2) {
            flag = true;
            printf("The digit %d is repeated %d times\n", i, digit_seen[i]);
        }

    }

    /* Checkpoint 2 */
    printf("\nDigit:\t\t");
    for (int i = 0; i < 10; i++) {
        printf("%d\t", i);
    }

    printf("\nOccurrences:\t");
    for (int i = 0; i < 10; ++i) {
        if (digit_seen[i] <= 1) {
            printf("\t");
        } else {
            printf("%d\t", digit_seen[i]);
        }
    }
    printf("\n");

    if (!flag) {
        printf("No repeated digits\n");
    }

    /* Chess board */
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            switch (i) {
                case 0:
                    board[i][j] = pieces[j];
                    break;
                case 1:
                    board[i][j] = 'p';
                    break;
                case 6:
                    board[i][j] = 'P';
                    break;
                case 7:
                    board[i][j] = toupper(pieces[j]);
                    break;
                default:
                    if (i % 2 == 0) {
                        if (alternate) {
                            board[i][j] = '.';
                        } else {
                            board[i][j] = ' ';
                        }
                        alternate = !alternate;
                    } else {
                        if (alternate) {
                            board[i][j] = ' ';
                        } else {
                            board[i][j] = '.';
                        }
                        alternate = !alternate;
                    }
            }
        }
    }

    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("\n");

        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("\t%c", board[i][j]);
        }
    }

    return 0;
}

