#include <stdio.h>

char * reverse(char *);

int main() {
    char str[] = "Reverse";
    printf("Reverse: %s\n", reverse(str));

    return 0;
}

char * reverse (char *str) {
    char *rtrn = str;
    char *beg = str;
    while (*str != '\0') {
        str++;
    }
    str--;
    while (beg < str) {
        char placeholder = *beg;
        *beg = *str;
        *str = placeholder;
        beg++;
        str--;
    }

    return rtrn;
}