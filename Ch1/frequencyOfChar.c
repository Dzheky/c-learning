#include <stdio.h>

int main() {
    int c;
    int charFrequency[26];

    for (int i = 0; i < 26; i++) {
       charFrequency[i] = 0;
    }

    while((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            charFrequency[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            charFrequency[c - 'A']++;
        }

    }
    putchar('\n');
    for (int i = 0; i < 26; i++) {
        if (charFrequency[i] > 0) {
            putchar('a' + i);
            printf(" - %d\n", charFrequency[i]);
        }
    }
}