#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_OP 100
#define NUMBER '0'
#define SIN '1'
#define EXP '2'
#define POW '3'
#define VARIABLE '4'

int getop(char []);
double getVariable(char);
void push(double);
void swapTop(void);
void printTop();
double pop(void);
void ungets(char s[]);

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
            case SIN:
                push(sin(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case VARIABLE:
                push(getVariable(s[0]));
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