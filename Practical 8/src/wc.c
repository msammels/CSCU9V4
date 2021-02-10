/**
 * CSCU9V4 - Practical 8
 * Michael Sammels
 * main.c
 * 12.04.2021
*/

#include <stdio.h>

int main(__attribute__((unused)) int argc, char *argv[]) {
    FILE *filePointer;

    /* If this is in the same directory, then the file name should be ../filename.txt
     * unless the text file is in the same directory as the executable */
    char *filename = argv[1];
    int character, numberOfCharacters = 0, numberOfWords = 0, numberOfLines = 0;
    filePointer = fopen(filename, "r");

    if (filePointer == NULL) {
        printf("\033[1m\033[31mCould not open file:\t%s\033[0m\033[0m", filename);

        return 1;
    }

    while ((character = getc(filePointer)) != EOF) {
        numberOfCharacters++;

        if (character == ' ' || character == '\n' || character == '\t' || character == '\r') {
                numberOfWords++;
            if (character == '\n') {
                numberOfLines++;
            }
        }
    }

    /* The last line is the end of the file, so we need to add to the count, so that it is not forgotten */
    numberOfLines++;
    fclose(filePointer);

    printf("\nThe number of characters in the file \033[33m%s\033[0m is \033[94m%d\033[0m.\n",
           filename, numberOfCharacters);
    printf("The number of words in the file \033[33m%s\033[0m is \033[32m%d\033[0m.\n",
           filename, numberOfWords);
    printf("The number of lines in the file \033[33m%s\033[0m is \033[31m%d\033[0m.\n",
           filename, numberOfLines);

    return 0;
}