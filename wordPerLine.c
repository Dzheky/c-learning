#include <stdio.h>

#define YES 1
#define NO 0

int main() {
    int c;
    int firstSpace = YES;

    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            if (firstSpace == YES) {
                firstSpace = NO;
                putchar('\n');
            }
        } else {
            firstSpace = YES;
            putchar(c);
        }
    }
}