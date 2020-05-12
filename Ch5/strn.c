/*
 * Write versions of the library functions strncpy, strncat
 * and strncmp, which operate on at most the first n characters of their argument strings
 */
#include <stdio.h>

#define STR_LEN 100

char* strnCpy(char *, char *, unsigned);
char* strnCat(char *, char *, unsigned);
int strnCmp(char *, char *, unsigned);

int main() {
    char s[STR_LEN] = "HLD";
    printf("STRNCPY: %s\n", strnCpy(s, "hello world", 5));
    printf("STRNCAT: %s\n", strnCat(s, " Evgeny K.", 7));
    printf("STRNCMP: %d\n", strnCmp("Hell", "Hello", 4));

    return 0;
}

char* strnCpy(char *s, char *t, unsigned n) {
    int i, len;
    char *scpy = s;
    while (*scpy++ != '\0')
        ;
    len = scpy - s - 1;
    scpy -= len + 1;
    for(i = 0; i < n && *t != '\0' && (*s++ = *t++); i++)
        ;
    if (len < n) {
        *s = '\0';
    }
    return scpy;
}

char* strnCat(char *s, char *t, unsigned n) {
    int i;
    char *beg = s;
    while (*++s != '\0')
        ;
    for (i = 0; i < n && (*s++ = *t++); i++)
        ;
    if (*s != '\0') {
        *s = '\0';
    }

    return beg;
}

int strnCmp(char *s, char *t, unsigned n) {
    int i;
    for (i = 0; i < n && *s == *t; s++, t++, i++) {
        if (*t == '\0') {
            return 0;
        }
    }
    if (i == n) {
        return 0;
    }

    return *s - *t;
}