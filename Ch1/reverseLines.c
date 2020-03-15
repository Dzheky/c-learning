#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int getLine(char str[], int limit);
int reverseLine(char from[], char to[], int length);

int main() {
    char line[MAX_LINE_LENGTH];
    char resultLine[MAX_LINE_LENGTH];
    int length;

    while((length = getLine(line, MAX_LINE_LENGTH)) > 0) {
        reverseLine(line, resultLine, length);
        printf("%s", resultLine);
    }
}

int getLine(char str[], int limit) {
    int c, i;

    i = 0;
    while((c = getchar()) != EOF && c != '\n') {
        if (i < MAX_LINE_LENGTH) {
            str[i] = c;
        }

        ++i;
    }

    if (c == '\n') {
        str[i] = '\n';
        ++i;
    }

    str[i] = '\0';

    return i;
}

int reverseLine(char from[], char to[], int length) {
    int i;
    int l;

    l = 0;
    for (i = length - 1; i >= 0; i--) {
        if (from[i] != '\n' && from[i] != '\0') {
            to[length - i - 2] = from[i];
            ++l;
        }
    }

    to[l] = '\n';
    ++l;
    to[l] = '\0';

    return l;
}