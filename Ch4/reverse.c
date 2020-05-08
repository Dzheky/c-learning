#include <stdio.h>
#include <string.h>

void reverse(char []);

int main() {
    char str[] = "Hello world";
    printf("Before: %s\n", str);
    reverse(str);

    printf("After: %s\n", str);
    return 0;
}

void reverse(char s[]) {
    static unsigned int i = 0;
    unsigned int x;
    x = strlen(s) - 1 - i;
    if (x != i) {
        int c = s[i];
        s[i++] = s[x];
        s[x] = c;
        reverse(s);
    }
}