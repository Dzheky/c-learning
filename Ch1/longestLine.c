#include <stdio.h>

#define MAX 10

int getLine(char str[], int limit);
void copy(char from[], char to[]);

int main() {
    int len; // Current line length
    int max; // Max length of the line
    char line[MAX]; // current line
    char longest[MAX]; // max line stored here

    max = 0;
    while ((len = getLine(line, MAX)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }

    printf("\nMAX: %d\n", max);

    if (max > 0) {
        printf("%s\n", longest);
    }

    return 0;
}

int getLine(char str[], int limit) {
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (i < limit) {
            str[i] = c;
        }
        ++i;
    }

    if (c == '\n') {
        str[i] = c;
        ++i;
    }

    str[i] = '\0';

    return i;
}

void copy(char from[], char to[]) {
    int i;

    i = 0;
    while((to[i] = from[i]) != '\n') {
        ++i;
    }
}