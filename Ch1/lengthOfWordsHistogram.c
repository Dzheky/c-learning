#include <stdio.h>

#define INSIDE 1
#define OUTSIDE 0

int main() {
    int inside = OUTSIDE;
    int c;
    int wordLength = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (inside == INSIDE) {
                putchar('\n');
                for (int i = 0; i < wordLength; i++) {
                    putchar('=');
                }
                printf(" %d\n\n", wordLength);
                wordLength = 0;
                inside = OUTSIDE;
            }
        } else {
            inside = INSIDE;
            ++wordLength;
            putchar(c);
        }
    }
}