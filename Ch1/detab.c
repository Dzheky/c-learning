#include <stdio.h>

int printTab(int len);

int main() {
    int c;
    int len;

    len = 0;
    while((c = getchar()) != EOF) {
        if (c == '\t') {
            len += printTab(len);
        } else {
            if (c == '\n') {
                len = 0;
            } else {
                ++len;
            }
            putchar(c);
        }
    }
}

int printTab(int len) {
    for(int i = 0; i < 8 - len % 8; i++) {
        putchar(' ');
    }

    return 8 - len % 8;
}