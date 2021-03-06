#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;
int singleBuf = 0;

int getch(void) {
    if (singleBuf) {
        int retValue = singleBuf;
        singleBuf = 0;
        return retValue;
    }
    return getchar();
}
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        singleBuf = c;
    }
}

void ungets(char s[]) {
    int len;
    for(len = 0; s[len] != '\0'; len++)
        ;
    if (len + bufp > BUFSIZE) {
        printf("ERROR: string is too large\n");
    }
    for (; len >= 0; len--) {
        ungetch(s[len]);
    }
}
