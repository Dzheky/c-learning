#include <stdio.h>
#include <stdlib.h>

#define MAX_OP 100
#define NUMBER '0'

int getop(char []);
void push(double);
void swapTop(void);
void printTop(void);
double pop(void);

int main() {
    int type;
    double op2;
    char s[MAX_OP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("ERROR: zero devisor\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push((int) pop() % (int) pop());
                } else {
                    printf("ERROR: zero devisor\n");
                }
                break;
            case '\n':
                printTop();
                break;
            default:
                printf("ERROR: unknown command\n");
                break;
        }
    }

    return 0;
}