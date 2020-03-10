#include <stdio.h>

int main() {
    char c = getchar();
    while (c != EOF) {
        if (c == 'H') {
            c = 'F';
        }
        putchar(c);
        c = getchar();
    }
}