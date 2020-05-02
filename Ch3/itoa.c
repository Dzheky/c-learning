#include <stdio.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    char s[1000];
    int n = -2147483647;
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}

void reverse(char s[]) {
    int i, j;
    int length = 0;
    char c;
    while (s[length] != '\0') length++;

    for(i = 0, j = length - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

    s[length] = '\0';
}

void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        s[i++] = n%10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-'; s[i] = '\0';
    }

    reverse(s);
}