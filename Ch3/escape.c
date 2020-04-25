#include <stdio.h>

#define MAX_STRING_SIZE 1000

void escape(char s[], char t[]);

int main() {
    char s[MAX_STRING_SIZE];
    char input[MAX_STRING_SIZE];
    int c;
    int i;

    for (i = 0; (c = getchar()) != EOF; i++) {
        input[i] = c;
    }
    input[i] = '\0';
    escape(s, input);

    printf("RESULT: %s\n", s);
    return 0;
}

void escape(char s[], char t[]) {
    int sourceI = 0;
    for (int i = 0; t[i] != '\0'; i++) {
        switch(t[i]) {
            case '\n':
                s[sourceI++] = '\\';
                s[sourceI] = 'n';
                break;
            case '\t':
                s[sourceI++] = '\\';
                s[sourceI] = 't';
                break;
            case ' ':
                s[sourceI++] = '\\';
                s[sourceI] = 's';
                break;
            default:
                s[sourceI] = t[i];
        }
        sourceI++;
    }
    s[sourceI] = '\0';
}