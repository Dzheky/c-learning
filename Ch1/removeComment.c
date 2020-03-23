#include <stdio.h>

int main() {
    int c, isInsideInline, isInsideEndOfLine;

    isInsideEndOfLine = 0;
    isInsideInline = 0;
    while ((c = getchar()) != EOF) {
        if (c == '/' && !isInsideInline && !isInsideEndOfLine) {
            int nextChar = getchar();
            if (nextChar == '/') {
                isInsideEndOfLine = 1;
            }

            if (nextChar == '*') {
                isInsideInline = 1;
            }
        }

        if (!isInsideInline && !isInsideEndOfLine) {
            putchar(c);
        }

        if (c == '*' && isInsideInline) {
            int nextChar = getchar();
            if (nextChar == '/') {
                isInsideInline = 0;
            }
        }

        if (c == '\n' && isInsideEndOfLine) {
            isInsideEndOfLine = 0;
        }

    }

    return 0;
}