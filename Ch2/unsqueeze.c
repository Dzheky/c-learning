#include <stdio.h>

void unsqeeze(char s1[], char s2[]);

int main() {
    char s1[] = "hello world";
    char s2[] = "old";

    unsqeeze(s1, s2);

    printf("%s\n", s1);

    return 0;
}

void unsqeeze(char s1[], char s2[]) {
    int i, j;

    for (j = i = 0; s1[i] != '\0'; i++) {
        int z = 0;
        while(s2[z] != '\0') {
            if (s2[z] == s1[i]) {
                break;
            }

            z++;
        }

        if (s2[z] != s1[i]) {
            s1[j++] = s1[i];
        }
    }

    s1[j] = '\0';
}