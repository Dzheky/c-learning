#include <stdio.h>

int main() {
    int c;
    double tabs = 0;
    double newlines = 0;
    double blanks = 0;

    while((c = getchar()) != EOF) {
        if (c == '\t') {
            ++tabs;
        }

        if (c == '\n') {
            ++newlines;
        }

        if (c == ' ') {
            ++blanks;
        }
    }

    printf("\nNumber of tabs are: \t%.0f\n", tabs);
    printf("Number of NL are: \t%.0f\n", newlines);
    printf("Number of blanks are: \t%.0f\n", blanks);
}