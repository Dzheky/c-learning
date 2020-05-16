#include <stdio.h>
#include <stdlib.h>

#define MAX_STOPS 10

int printTab(int len);
int printTabCustomStops(int len, char * argv[], int argc);

int stops[MAX_STOPS];
int stop = 8;
int after = 0;

int main(int argc, char * argv[]) {
    int c;
    int len;
    int isArgs = argc > 1;

    for (int i = 0; i < argc -1; i++) {
        if (*argv[i] == '-') {
            switch (*++argv[i]) {
                case 'n':
                    stop = atoi(argv[++i]);
                    isArgs = 0;
                    break;
                case 'm':
                    after = atoi(argv[++i]);
                    isArgs = 0;
                    break;
            }
        }
    }

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
    if (len > after) {
        int nspaces = stop - (len - after) % stop;
        for(int i = 0; i < nspaces; i++) {
            putchar(' ');
        }

        return nspaces;
    }
    for (int i = 0; i < after; i++) {
        putchar(' ');
    }
    return after;
}