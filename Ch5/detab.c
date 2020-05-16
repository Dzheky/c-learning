#include <stdio.h>
#include <stdlib.h>

#define MAX_STOPS 10

int printTab(int len);
int printTabCustomStops(int len, char * argv[], int argc);

int stops[MAX_STOPS];

int main(int argc, char * argv[]) {
    int c;
    int len;
    int isArgs = argc > 1;

    len = 0;
    while((c = getchar()) != EOF) {
        if (c == '\t') {
            len += isArgs ? printTabCustomStops(len, argv, argc) : printTab(len);
        } else {
            if (c == '\n') {
                len = 0;
            } else {
                ++len;
            }
            putchar(c);
        }
    }
}

int printTabCustomStops(int len, char * argv[], int argc) {
    int length;
    int stop = 1;

    while(atoi(argv[stop]) < len && stop < argc - 1) {
        stop++;
    }

    if (atoi(argv[stop]) < len) {
        return printTab(len);
    }

    length = atoi(argv[stop]) - len;

    for (int i = 0; i < length; i++) {
        putchar(' ');
    }

    return length;
}

int printTab(int len) {
    for(int i = 0; i < 8 - len % 8; i++) {
        putchar(' ');
    }

    return 8 - len % 8;
}