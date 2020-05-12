#include <stdio.h>

#define STR_LEN 200

void strCat(char *, char *);

int main() {
    char str[STR_LEN];
    str[0] = 'h';
    str[1] = '\0';
    strCat(str, "ello world");

    printf("%s\n", str);

    return 0;
}

void strCat(char *s, char *t) {
    while(*++s != '\0')
        ;
    while((*s++ = *t++))
        ;
}