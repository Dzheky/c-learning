#include <stdio.h>

#define MAX_LENGTH 1000

void expand(char s1[], char s2[]);

int main() {
    char source[MAX_LENGTH];
    char input[MAX_LENGTH];
    int c;
    int i = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n') {
            input[i] = '\0';
            expand(input, source);
            printf("result: %s\n", source);
            i = 0;
        }
        input[i++] = c;
    }

    return 0;
}

void expand(char s1[], char s2[]) {
    int i, si, begin, end;
    int after = 0;
    for (i = 0, si = 0, begin = -1, end = -1; s1[i] != '\0'; i++) {
        if (s1[i] != '-') {
            if (after) {
                end = s1[i];
            } else {
                begin = s1[i];
                s2[si++] = s1[i];
            }
        } else {
            if (begin != -1) {
                after = 1;
            } else {
                s2[si++] = s1[i];
            }
        }

        if (begin != -1 && end != -1 && after) {
            for (int z = 0; z < end - begin; z++) {
                s2[si++] = z + begin + 1;
            }
            begin = end;
            end = -1;
            after = 1;
        }
    }

    s2[si] = '\0';
}