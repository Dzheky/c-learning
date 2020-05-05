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

void printTop(void) {
    if (stackPosition > 0) {
        printf("\t%.8g\n", stack[stackPosition - 1]);
    } else {
        printf("ERROR: Stack is empty\n");
    }
}

void swapTop(void) {
    if (stackPosition > 1) {
        double placer = stack[stackPosition - 1];
        stack[stackPosition] = stack[stackPosition - 2];
        stack[stackPosition - 2] = placer;
    } else {
        printf("ERROR: Nothing to swap");
    }
}

void clearstack(void) {
    stackPosition = 0;
}

double pop(void) {
    if (stackPosition > 0) {
        return stack[--stackPosition];
    } else {
        printf("ERROR: Stack is empty\n");
        return 0.0;
    }
}