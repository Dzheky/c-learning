#include <stdio.h>

void printTabs(int numOfTabs, int numOfSpaces);

int main() {
    int c, length, blanksCount;

    length = 0;
    blanksCount = 0;
    while((c = getchar()) != EOF) {
        if (c == '\n') {
            length = 0;
            putchar(c);
            continue;
        }
        if (c != ' ') {
            if (blanksCount != 0) {
                int totalTabs = (length + blanksCount) / 8;
                int numOfTabs = totalTabs - (length / 8);
                int numOfSpaces = (length + blanksCount) - totalTabs * 8;
                if (numOfTabs == 0) {
                    numOfSpaces = blanksCount;
                }
                printTabs(numOfTabs, numOfSpaces);
                length += blanksCount;
                blanksCount = 0;
            }
            ++length;
            putchar(c);
        } else {
            ++blanksCount;
        }
    }


    return 0;
}

void printTabs(int numOfTabs, int numOfSpaces) {
    for (int i = 0; i < numOfTabs; i++) {
        putchar('\t');
    }

    for (int i = 0; i < numOfSpaces; i++) {
        putchar(' ');
    }
}