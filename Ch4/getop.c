#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_VARIABLES 26
#define NUMBER '0'
#define SIN '1'
#define EXP '2'
#define POW '3'
#define VARIABLE '4'

int getch(void);
void ungetch(int);
char variables[MAX_VARIABLES];

int getop(char s[]) {
    static int holder = 0;
    int i, c;
    i = 0;
    if (holder == 0) {
        c = getch();
    } else {
        c = holder;
        holder = 0;
    }
    while ((s[i] = c) == ' ' || c == '\t') {
        c = getch();
    }
    s[1] = '\0';

    if (c == '-' && !isdigit(s[++i] = c = getch())) {
        holder = c;
        c = '-';
    }

    if (c == '\n') {
        return c;
    }

    if (!isdigit(c) && c != '.') {
        while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != EOF) {
            s[++i] = getch();
        }
        holder = s[i];
        s[i] = '\0';
        if (strncmp(s,"exp", 3) == 0) {
            c = EXP;
        }
        if (strncmp(s,"sin", 3) == 0) {
            c = SIN;
        }
        if (strncmp(s,"pow", 3) == 0) {
            c = POW;
        }

        if (c >= 'a' && c <= 'z') {
            s[0] = c;
            s[1] = '\0';
            return VARIABLE;
        }

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
        holder = c;
    }

    return NUMBER;
}