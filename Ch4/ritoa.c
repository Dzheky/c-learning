#include <stdio.h>
#define MAX_ARR 1000

void ritoa(char [], int);

int main() {
    char str[MAX_ARR];
    ritoa(str, 1034);
    printf("number in string: %s\n", str);
    return 0;
}

void ritoa(char s[], int d) {
    static int i = 0;
    static int x = 0;
    i++;
    if (d != 0) {
        ritoa(s, d / 10);
        s[x++] = d % 10 + '0';
    } else {
        s[x] = '\0';
        i = 0;
        x = 0;
    }
}