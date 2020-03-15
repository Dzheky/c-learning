#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int getLine(char str[], int limit);
int removeTrailingBlanks(char from[], char to[], int length);

int main() {
    char line[MAX_LINE_LENGTH];
    char resultLine[MAX_LINE_LENGTH];
    int length;
    int resultLength;

    while((length = getLine(line, MAX_LINE_LENGTH)) > 0) {
        resultLength = removeTrailingBlanks(line, resultLine, length);
        if (resultLength > 0) {
            printf("%s", resultLine);
        }
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

int removeTrailingBlanks(char from[], char to[], int length) {
    int i;
    int isFirstNonBlank;
    int l;

    l = 0;
    isFirstNonBlank = 0;
    for (i = length - 1; i >= 0; i--) {
        if (from[i] != ' ' && from[i] != '\t' && from[i] != '\0' && from[i] != '\n' && isFirstNonBlank == 0) {
            isFirstNonBlank = 1;
            to[i] = from[i];
            ++l;
        } else if (isFirstNonBlank == 1) {
            to[i] = from[i];
            ++l;
        }
    }

    if (l > 0) {
        to[l] = '\n';
        ++l;
    }

    to[l] = '\0';

    return l;
}