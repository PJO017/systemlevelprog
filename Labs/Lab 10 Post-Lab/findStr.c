#include <stdio.h>
#include <string.h>

void findStr();

void main() {
    findStr();
}

void findStr() {
    char smallestString[20];
    char longestString[20];

    while (1)
    {
        char string[20];
        printf("Enter word: ");
        scanf("%s", &string);

        if (strlen(string) == 4) {
            break;
        }

        if (strlen(smallestString) == 0) {
            strcpy(smallestString, string);
        }

        if (strcmp(string, smallestString) < 0) {
            strcpy(smallestString, string);
        } 
        if (strcmp(string, longestString) > 0) {
            strcpy(longestString, string);
        }
    }

    printf("Smallest word: %s \n", smallestString);
    printf("Largest word: %s \n", longestString);
    printf("");
}