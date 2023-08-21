#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int min(int x, int y) {
    return x > y ? y : x;
}

int max(int x, int y) {
    return x > y ? x : y;
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int rnd() {
    static unsigned int X = 0xAB0BA420;
    return (X *= 3) >> 1;
}

typedef struct Task Task;
typedef struct StackNode StackNode;

struct Task {
    int l, r;
};

struct StackNode {
    Task task;
    StackNode *p;
};

void pop(StackNode **head, int *l, int *r) {
    *l = (*head)->task.l;
    *r = (*head)->task.r;

    StackNode *popped = *head;
    *head = (*head)->p;
    free(popped);
}

void push(StackNode **head, int l, int r) {
    StackNode *node = (StackNode *) malloc(sizeof(StackNode));
    node->task.l = l;
    node->task.r = r;

    node->p = *head;
    *head = node;
}

int empty(StackNode *head) {
    return head == 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *) malloc(sizeof(int) * n);
    int *b = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    StackNode *head = 0;
    push(&head, 0, n);
    int l, r;
    while (!empty(head)) {
        int l, r;
        pop(&head, &l, &r);
        if (r - l <= 1)
            continue;
        int piv = a[l + rnd() % (r - l)];
        int x = 0;
        int y = 0;
        int z = 0;
        for (int i = l; i < r; ++i) {
            if (a[i] < piv)
                x++;
            else if (a[i] == piv)
                y++;
            else
                z++;
        }
        z += y += x;
        for (int i = l; i < r; ++i) {
            if (a[i] < piv)
                b[--x] = a[i];
            else if (a[i] == piv)
                b[--y] = a[i];
            else
                b[--z] = a[i];
        }
        memcpy(a + l, b, sizeof(int) * (r - l));
        push(&head, l, l + y);
        push(&head, l + z, r);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    puts("");
    free(a);
    free(b);
    return 0;
}