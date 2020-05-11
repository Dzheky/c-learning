#include <stdio.h>
#include <ctype.h>

#define BUF_SIZE 100

int getch(void);
void ungetch(int);
int getint(int *pn);

int buf[BUF_SIZE];
int buffLocation = 0;

int main() {
    int result;
    getint(&result);

    printf("number: %d\n", result);
    return 0;
}

int getint(int *pn) {
    int sign, c;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '-' || c == '+') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;

    if (c == EOF) {
        ungetch(c);
    }

    return c;
}

int getch(void) {
    if (buffLocation > 0) {
        return buf[--buffLocation];
    }

    return getchar();
}

void ungetch(int c) {
    if (buffLocation > BUF_SIZE) {
        printf("ERROR: Buffer is full\n");
    } else {
        buf[buffLocation++] = c;
    }
}