#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE 100

int getLine(char str[], int limit);
void quickSort(void *holder[], int left, int right, int (*comp)(const void *, const void *));
int numcmp(const char *, const char *);

int lastn = 10;
int reverse = 0;
int caseinsensive = 0;
char * holder[MAX_LINES];
int currLine = 0;


int main(int argc, char * argv[]) {
    char buf[MAX_LINE];
    int lineLength = 0;
    int numeric = 0;
    int (*func)(const void*, const void*);

    for (int i = 1; i < argc; i++) {
        if (argc > 1 && *argv[i] == '-' && isdigit(*(argv[i] + 1))) {
            lastn = atoi((argv[i] + 1)) > 0 ? atoi((argv[i] + 1)) : 10;
        }

        if (strcmp(argv[i], "-n") == 0) {
            numeric = 1;
        }

        if (strcmp(argv[i], "-r") == 0) {
            reverse = 1;
        }

        if (strcmp(argv[i], "-f") == 0) {
            caseinsensive = 1;
        }

    }

    while((lineLength = getLine(buf, MAX_LINE)) != 0) {
        char * p = malloc(lineLength + 1);
        strcpy(p, buf);
        holder[currLine++] = p;
    }

    if (numeric) {
        func = (int (*)(const void*, const void*)) numcmp;
    } else if (caseinsensive) {
        func = (int (*)(const void*, const void*)) strcasecmp;
    } else {
        func = (int (*)(const void*, const void*)) strcmp;
    }

    quickSort((void**) holder, 0, currLine-1, func);

    if (currLine < lastn) {
        for (int i = 0; i < currLine; i++) {
            printf("%s\n", holder[i]);
        }
    } else {
        for (int i = 0; i < lastn; i++) {
            printf("%s\n", holder[currLine - lastn + i]);
        }
    }


    return 0;
}

void quickSort(void *v[], int left, int right, int (*comp)(const void *, const void *)) {
    int i, last;
    void swap(void *v[], int, int);
    if (left >= right) {
        return;
    }
    swap(v, left, (left + right)/2); last = left;
    for (i = left+1; i <= right; i++)  {
        if (reverse ? ((*comp)(v[i], v[left]) > 0) : ((*comp)(v[i], v[left]) < 0)) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    quickSort(v, left, last-1, comp);
    quickSort(v, last+1, right, comp);
}

int getLine(char str[], int limit) {
    int i, c;

    i = 0;
    while((c = getchar()) != EOF && c != '\n') {
        if (i < limit) {
            str[i] = c;
        }
        ++i;
    }

    str[i] = '\0';

    return i;
}

int numcmp(const char *s1, const char *s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i]; v[i] = v[j]; v[j] = temp;
}