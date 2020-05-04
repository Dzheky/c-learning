#include <stdio.h>

#define MAX_STACK 100

int stackPosition = 0;
double stack[MAX_STACK];

void push(double val) {
    if (stackPosition < MAX_STACK) {
        stack[stackPosition++] = val;
    } else {
        printf("ERROR: Stack is full\n");
    }
}

double pop(void) {
    if (stackPosition > 0) {
        return stack[--stackPosition];
    } else {
        printf("ERROR: Stack is empty\n");
        return 0.0;
    }
}