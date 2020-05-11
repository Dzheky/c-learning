#include <stdio.h>
#include <ctype.h>

#define BUF_SIZE 100

int getch(void);
void ungetch(int);
int getfloat(double *pn);

int buf[BUF_SIZE];
int buffLocation = 0;

int main() {
    double result;
    getfloat(&result);

    printf("number: %f\n", result);
    return 0;
}

int getfloat(double *pn) {
    int c;
    double devisor = 1.0;
    double sign;
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1.0 : 1.0;

    if (c == '-' || c == '+') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            return 0;
        }
    }

    for (*pn = 0.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
    }


    if (c == '.') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            return 0;
        }
        for (; isdigit(c); c = getch(), devisor *= 10.0) {
            *pn = 10.0 * *pn + (c - '0');
        }
    }


    *pn *= sign;
    *pn /= devisor;


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