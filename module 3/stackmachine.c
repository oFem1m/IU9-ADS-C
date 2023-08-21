#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 100500

typedef struct Stack Stack;

struct Stack {
    long long *a;
    int p;
};

long long pop(Stack *stack) {
    return stack->a[--(stack->p)];
}

void push(Stack *stack, int x) {
    stack->a[stack->p++] = x;
}

int main() {
    Stack stack;
    stack.a = (long long *) malloc(sizeof(long long) * maxn);
    stack.p = 0;
    char s[10];
    while (1) {
        scanf("%s", s);
        if (strcmp(s, "CONST") == 0) {
            long long x;
            scanf("%lld", &x);
            push(&stack, x);
        } else if (strcmp(s, "ADD") == 0) {
            long long x, y;
            x = pop(&stack);
            y = pop(&stack);
            push(&stack, x + y);
        } else if (strcmp(s, "SUB") == 0) {
            long long x, y;
            x = pop(&stack);
            y = pop(&stack);
            push(&stack, x - y);
        } else if (strcmp(s, "MUL") == 0) {
            long long x, y;
            x = pop(&stack);
            y = pop(&stack);
            push(&stack, x * y);
        } else if (strcmp(s, "DIV") == 0) {
            long long x, y;
            x = pop(&stack);
            y = pop(&stack);
            push(&stack, x / y);
        } else if (strcmp(s, "MAX") == 0) {
            long long x, y;
            x = pop(&stack);
            y = pop(&stack);
            push(&stack, x > y ? x : y);
        } else if (strcmp(s, "MIN") == 0) {
            long long x, y;
            x = pop(&stack);
            y = pop(&stack);
            push(&stack, x > y ? y : x);
        } else if (strcmp(s, "NEG") == 0) {
            long x;
            x = pop(&stack);
            push(&stack, -x);
        } else if (strcmp(s, "DUP") == 0) {
            long x;
            x = pop(&stack);
            push(&stack, x);
            push(&stack, x);
        } else if (strcmp(s, "SWAP") == 0) {
            long long x, y;
            x = pop(&stack);
            y = pop(&stack);
            push(&stack, x);
            push(&stack, y);
        } else if (strcmp(s, "END") == 0) {
            break;
        }
    }
    printf("%lld", pop(&stack));
    free(stack.a);
}