#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

char * lineptr[MAXLINES];
char linestore[MAXLINES];

int getLine(char *, int);
int readLines(char *lineptr[], char linestore[], int maxlines);
void writeLines(char *lineptr[], int nlines);

void quickSort(char *lineptr[], int left, int right);

int main() {
    int nlines;
    if ((nlines = readLines(lineptr, linestore, MAXLINES)) >= 0) {
        writeLines(lineptr, nlines);
        return 0;
    } else {
        printf("Too many lines\n");
        return 1;
    }
}

int readLines(char *lineptr[], char * linestor, int maxlines) {
    int len, nlines;
    char * p = linestor;
    char line[MAXLEN];
    char *linestop = linestor + MAXLINES;

    while((len = getLine(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || p + len > linestop) {
            return -1;
        } else {
            line[len++] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }

    return nlines;
}

int getLine(char *str, int limit) {
    int c;
    char * beg = str;

    while((c = getchar()) != EOF && c != '\n') {
        *str = c;
        str++;
    }
    *str = '\0';

    return str - beg;
}

void writeLines(char *lineptr[], int nlines) {
    while (nlines-- > 0) {
        printf("Line: %s\n", *lineptr++);
    }
}