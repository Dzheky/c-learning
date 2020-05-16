#include <stdio.h>
#include <ctype.h>

#define MAX_STACK 1000

void push(int);
int pop(void);
int atoi(char *);

int stackIndex = 0;
int stack[MAX_STACK];

int main(int argc, char * argv[]) {
    int second;

    while (--argc > 0) {
        switch(**++argv) {
            case '-':
                second = pop();
                push(pop() - second);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                printf("HERE\n");
                push(pop() * pop());
                break;
            case '/':
                second = pop();
                push(pop() / second);
                break;
            default:
                push(atoi(*argv));
        }
    }

    printf("RESULT: %d\n", pop());
    stackIndex = 0;

    return 0;
}

void push(int n) {
    if (stackIndex < MAX_STACK) {
        stack[stackIndex++] = n;
    } else {
        printf("ERROR: Stack is full\n");
    }
}

int pop(void) {
    if (stackIndex != 0) {
        return stack[--stackIndex];
    }
    printf("ERROR: Stack is empty\n");
    return 0;
}

int atoi(char * str) {
    if (!isdigit(*str)) {
        printf("NOT NUMBER\n");
        return 0;
    }
    int power = 1;
    int result = *str - '0';
    while (*++str != '\0') {
        power *= 10;
        result = result * power + *str - '0';
    }

    return result;
}