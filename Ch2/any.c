#include <stdio.h>

signed int any(char s1[], char s2[]);

int main() {
    char s1[] = "hello";
    char s2[] = "o";

    int i = any(s1, s2);

    printf("%d\n", i);

    return 0;
}

signed int any(char s1[], char s2[]) {
    signed int i = -1;

    for (i = 0; s1[i] != '\0'; i++) {
        int j = 0;
        while (s2[j++] != '\0') {
            if (s2[j - 1] == s1[i]) {
                return i;
            }
        }
    }

    return i;
}