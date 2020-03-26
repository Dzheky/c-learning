/*
 * Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||
 */

#include <stdio.h>

int main() {
    int c;
    int lim = 10;
    char str[lim];

    for (int i = 0; i < lim-1; ++i) {
        if ((c=getchar()) == '\n') {
            break;
        }

        if (c == EOF) {
            break;
        }

        str[i] = c;
    }

    str[lim - 1] = '\0';

    printf("%s\n", str);

    return 0;
}