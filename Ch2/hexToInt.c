#include <stdio.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 8

short isHex(void);
short getNextHex(char hex[]);
int htoi(char s[]);

int main() {
    char hex[MAX_HEX_LENGTH + 1];
    short trigger = 0;

    while (trigger != -1) {
        trigger = isHex();
        if (trigger == 1) {
            trigger = getNextHex(hex);
        }
    }


    return 0;
}

int htoi(char s[]) {
    int result = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            result = result * 16 + s[i] - '0';
        }

        if (s[i] >= 'a' && s[i] <= 'f') {
            result = result * 16 + s[i] - 'a' + 10;
        }

        if (s[i] >= 'A' && s[i] <= 'F') {
            result = result * 16 + s[i] - 'A' + 10;
        }
    }

    return result;
}

short getNextHex(char hex[]) {
    int c, i;

    for (i = 0; isxdigit(c = getchar()) != 0 && i < MAX_HEX_LENGTH; i++) {
        hex[i] = c;
    }

    hex[i] = '\0';

    if (c == EOF) {
        return -1;
    }

    printf("%d%c", htoi(hex), c);

    return 0;
}

short isHex() {
    int unsigned first = getchar();
    int unsigned second = getchar();

    if (first == EOF || second == EOF) {
        return -1;
    }

    if (first == '0' && (second == 'x' || second == 'X')) {
        return 1;
    }

    putchar(first);
    putchar(second);

    return 0;
}