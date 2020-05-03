#include <stdio.h>

int strindex(char str[], char ocur[]);
int strlength(char str[]);

int main() {
    printf("%d\n", strindex("Hello Hello", "Hello"));
    return 0;
}

int strlength(char str[]) {
    int length = 0;
    while (str[length] != '\0') length++;

    return length;
}

int strindex(char str[], char ocur[]) {
    int j, i, k;
    for (i = strlength(str) - 1; i >= 0; i--) {
        for (j = i, k = strlength(ocur) - 1; k >= 0 && str[j] == ocur[k]; j--, k--)
            ;
        if (k < 0 && str[j+1] == ocur[k+1]) {
            return j+1;
        }
    }

    return -1;
}
