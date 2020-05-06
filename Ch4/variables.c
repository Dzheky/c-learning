#include <stdio.h>

#define MAX_VARIABLES 26

double getVariable(char);
void setVariable(char, double);

double vars[MAX_VARIABLES];

double getVariable(char c) {
    if (c - 'a' > MAX_VARIABLES || c - 'a' < 0) {
        printf("ERROR: Wrong variable\n");
        return 0.0;
    }

    return vars[c - 'a'];
}

void setVariable(char c, double d) {
    if (c - 'a' > MAX_VARIABLES || c - 'a' < 0) {
        printf("ERROR: Wrong variable\n");
    } else {
        vars[c - 'a'] = d;
    }
}