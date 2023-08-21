#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define maxn 300500

int max(int x, int y) {
    return x > y ? x : y;
}

typedef struct Queue {
    int p1;
    int p2;
    int *s1;
    int *s2;
    int *m1;
    int *m2;
} Queue;

bool empty(Queue *q) {
    return q->p1 == 0 && q->p2 == 0;
}

void enque(Queue *q, int x) {
    q->s1[q->p1] = x;
    q->m1[q->p1 + 1] = max(q->m1[q->p1], q->s1[q->p1]);
    (q->p1)++;
}

int deque(Queue *q) {
    if (q->p2 == 0) {
        while (q->p1) {
            q->s2[(q->p2)++] = q->s1[--(q->p1)];
            q->m2[q->p2] = max(q->m2[q->p2 - 1], q->s2[q->p2 - 1]);
        }
    }
    return q->s2[--(q->p2)];
}

int maximum(Queue *q) {
    return max(q->m1[q->p1], q->m2[q->p2]);
}

int main() {
    Queue q;
    q.p1 = 0;
    q.p2 = 0;
    q.s1 = (int *) malloc(sizeof(int) * maxn);
    q.s2 = (int *) malloc(sizeof(int) * maxn);
    q.m1 = (int *) malloc(sizeof(int) * maxn);
    q.m2 = (int *) malloc(sizeof(int) * maxn);
    q.m1[0] = q.m2[0] = 1 << 31;
    char s[10];
    while (1) {
        scanf("%s", s);
        if (strcmp(s, "ENQ") == 0) {
            int x;
            scanf("%d", &x);
            enque(&q, x);
        } else if (strcmp(s, "DEQ") == 0) {
            int x = deque(&q);
            printf("%d\n", x);
        } else if (strcmp(s, "EMPTY") == 0) {
            puts(empty(&q) ? "true" : "false");
        } else if (strcmp(s, "MAX") == 0) {
            int x = maximum(&q);
            printf("%d\n", x);
        } else if (strcmp(s, "END") == 0) {
            break;
        }
    }
    free(q.s1);
    free(q.s2);
    free(q.m1);
    free(q.m2);
    return 0;
}