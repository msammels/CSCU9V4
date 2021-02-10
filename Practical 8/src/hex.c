/**
 * CSCU9V4 - Practical 8
 * Michael Sammels
 * hex.c
 * 12.04.2021
*/

#include <stdio.h>
#include <ctype.h>

#define BYTE_SIZE 10
#define SIZE(x) sizeof(x) / sizeof(x[0])

int main(__attribute__((unused)) int argc, char *argv[]) {
    FILE *filePointer;
    char *filename = argv[1], array[BYTE_SIZE] = {0};
    int character, position = 0, offset = 0;
    filePointer = fopen(filename, "rb");

    if (filePointer == NULL) {
        printf("\033[1m\033[31mCould not open file:\t%s\033[0m\033[0m",filename);

        return 1;
    }

    printf("Offset\t\t\t\tBytes\t\t\t\tCharacters"
           "\n-------\t"
           "-----------------------------\t"
           "----------\n");

    while ((character = getc(filePointer)) != EOF) {
        if (offset % BYTE_SIZE == 0) {
            printf("%4d\t", offset);
        }

        array[position] = character;
        printf("%02X", character);

        ++position, ++offset;

        if (position == BYTE_SIZE) {
            for (int i = 0; i < SIZE(array); ++i) {
                if (i == 0) {
                    printf("\t");
                }

                if (isprint(array[i])) {
                    printf("%c", array[i]);
                } else {
                    printf(".");
                }
            }

            printf("\n");
            position = 0;
        }
    }

    /* When the end of the file is hit, the last characters need to be printed */
    for (int i = 0; i < position; ++i) {
        if (i == 0) {
            for(int j = 0; j < BYTE_SIZE - position; ++j) {
                printf("\t");
            }
        }

        if (isprint(array[i])) {
            printf("%c", array[i]);
        } else {
            printf(".");
        }
    }

    fclose(filePointer);

    return 0;
}