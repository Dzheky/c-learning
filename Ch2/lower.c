#include <stdio.h>

#define MAX_STRING 1000

void lower(char str[], int len);

int main() {
    char c;
    char str[MAX_STRING];
    int i = 0;
    while ((c = getchar()) != EOF || i == MAX_STRING) {
        str[i++] = c;
    }
    str[i] = '\0';
    lower(str, i);
    printf("%s\n", str);

    return 0;
}

void lower(char str[], int len) {
    for (int i = 0; i < len; i++) {
        str[i] = str[i] >= 'A' && str[i] <= 'Z' ? str[i] - 'A' + 'a' :  str[i];
    }

}