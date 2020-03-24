#include <stdio.h>

#define LIMIT 50
#define WORD_LIMIT 1000

void getNextPart(char getNextWord[], int result[]);

int main() {
    int length, last;
    int wordStatistics[2];
    char nextWord[WORD_LIMIT];

    last = 0;
    length = 0;
    while(last != 1) {
        getNextPart(nextWord, wordStatistics);
        if (length + wordStatistics[0] + 1 > LIMIT) {
            printf("\n%s ", nextWord);
            length = wordStatistics[0] + 1;
        } else {
            printf("%s ", nextWord);
            length += wordStatistics[0] + 1;
        }

        if (wordStatistics[1] == 1) {
            last = 1;
        }
    }

    return 0;
}

void getNextPart(char nextWord[], int result[]) {
    int c, i;
    i = 0;

    while((c = getchar()) != EOF && c != '\n' && c != ' ') {
        nextWord[i] = c;
        i++;
    }

    if (i == 0) {
        nextWord[0] = ' ';
        nextWord[1] = '\0';
        result[0] = 1;
        result[1] = 0;
    }

    nextWord[i] = '\0';
    result[0] = i;
    result[1] = c == EOF;

}