#include <stdio.h>

#define MAX_STR 1000

void reverse(char str[]);
void itoa(int n, char str[], unsigned min);

int main() {
    char str[MAX_STR];
    itoa(154, str, 5);
    printf("%s\n", str);
    return 0;
}

void itoa(int n, char str[], unsigned min) {
    int i;
    while (n != 0) {
        str[i] = n % 10 + '0';
        n /= 10;
        i++;
    }

    while (i < min) {
        str[i] = '0';
        i++;
    }

    str[i] = '\0';
    reverse(str);
}

void reverse(char str[]) {
    int j, i, length;
    length = 0;
    while(str[length] != '\0') length++;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        char holder = str[i];
        str[i] = str[j];
        str[j] = holder;
    }

    str[length] = '\0';
}