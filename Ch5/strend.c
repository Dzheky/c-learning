#include <stdio.h>

short strEnd(char *, char *);

int main() {
    printf("%d\n", strEnd("Hello world", "world"));
    return 0;
}

short strEnd(char *s, char *t) {
    char *beg = t;
    while (*++s != '\0')
        ;
    while (*++t != '\0')
        ;
    while (*--s == *--t) {
        if (t == beg) {
            return 1;
        }
    }

    return 0;
}