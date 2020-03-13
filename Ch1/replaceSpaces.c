#include <stdio.h>

#define SPACE_EXIST 1
#define NO_SPACE 0

int main() {
    int spaceFlag = NO_SPACE;
    int c;

    while((c = getchar()) != EOF) {
        if (c == ' ' && spaceFlag == NO_SPACE) {
            spaceFlag = SPACE_EXIST;
            putchar(c);
        } else if (spaceFlag == NO_SPACE) {
            putchar(c);
        } else if (spaceFlag == SPACE_EXIST) {
            if (c != ' ') {
                spaceFlag = NO_SPACE;
                putchar(c);
            }
        }
    }
}