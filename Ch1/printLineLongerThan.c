#include <stdio.h>

#define MAX_LINE_LENGTH 1000
#define MIN_LINE_LIMIT 80

int getLine(char str[], int limit);

int main() {
    char line[MAX_LINE_LENGTH];
    int currLength;

    while ((currLength = getLine(line, MAX_LINE_LENGTH)) > 0) {
        if (currLength > MIN_LINE_LIMIT) {
            printf("%s", line);
        }
    }
}

int getLine(char str[], int limit) {
    int i, c;

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