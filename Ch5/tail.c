#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE 100

int getLine(char str[], int limit);

int lastn = 10;
char * holder[MAX_LINES];
int currLine = 0;


int main(int argc, char * argv[]) {
    char buf[MAX_LINE];
    int lineLength = 0;
    if (argc > 1 && *argv[1] == '-' && *(argv[1] + 1) == 'n') {
        lastn = atoi(argv[2]) > 0 ? atoi(argv[2]) : 10;
    }

    while((lineLength = getLine(buf, MAX_LINE)) != 0) {
        char * p = malloc(lineLength + 1);
        strcpy(p, buf);
        holder[currLine++] = p;
    }

    if (currLine < lastn) {
        for (int i = 0; i < currLine; i++) {
            printf("%s\n", holder[i]);
        }
    } else {
        for (int i = 0; i < lastn; i++) {
            printf("%s\n", holder[currLine - lastn + i]);
        }
    }


    return 0;
}

int getLine(char str[], int limit) {
    int i, c;

    i = 0;
    while((c = getchar()) != EOF && c != '\n') {
        if (i < limit) {
            str[i] = c;
        }
        ++i;
    }

    str[i] = '\0';

    return i;
}