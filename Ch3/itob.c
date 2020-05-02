#include <stdio.h>

#define MAX_STR_LENGTH 1000

void itob(int n, char str[], unsigned short base);
char itobasec(unsigned int n);
void reverse(char s[]);

int main() {
    char baseStr[MAX_STR_LENGTH];
    itob(150234, baseStr, 16);
    printf("%s\n", baseStr);
    return 0;
}

void itob(int n, char str[], unsigned short base) {
    if (base == 1) {
        str[0] = '1';
        str[1] = '\0';
        return;
    }
    int i = 0;
    while (n != 0) {
        str[i] = itobasec(n % base);
        n /= base;
        i++;
    }
    str[i] = '\0';
    reverse(str);
}

void reverse(char s[]) {
    int j, i;
    int length = 0;
    while (s[length] != '\0') length++;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        char holder = s[i];
        s[i] = s[j];
        s[j] = holder;
    }
    s[length] = '\0';
}

char itobasec(unsigned int n) {
    if (n < 10) {
        return '0' + n;
    } else if (n < 37) {
        return 'A' + n - 10;
    }

    return '%';
}