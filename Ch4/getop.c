#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c;
    i = 0;
    while ((s[i] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (c == '-' && !isdigit(s[++i] = c = getch())) {
        ungetch(c);
        c = '-';
    }

    if (c == '\n') {
        return c;
    }

    if (!isdigit(c) && c != '.') {
        while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != EOF) {
            s[++i] = getch();
        }
        ungetch(s[i]);
        s[i] = '\0';
        return c;
    }
    if (isdigit(c)) {
        while(isdigit(s[++i] = c = getch()))
            ;
    }

    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER;
}