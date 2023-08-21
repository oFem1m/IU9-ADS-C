#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Queue Queue;

struct Queue {
    int head;
    int tail;
    int size;
    int capacity;
    int *a;
};

void initQueue(Queue *q) {
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    q->capacity = 4;
    q->a = (int *) malloc(sizeof(int) * q->capacity);
}

bool empty(Queue *q) {
    return q->size == 0;
}

void enque(Queue *q, int x) {
    if (q->head == q->tail && !empty(q)) {
        int *b = q->a;
        q->capacity *= 2;
        q->a = (int *) malloc(sizeof(int) * q->capacity);
        int i = 0;
        do {
            q->a[i++] = b[q->tail++];
            if (q->tail == q->capacity / 2)
                q->tail = 0;
        } while (q->tail != q->head);
        q->tail = 0;
        q->head = i;
        free(b);
    }
    q->size++;
    q->a[q->head++] = x;
    if (q->head == q->capacity)
        q->head = 0;
}

int deque(Queue *q) {
    q->size--;
    int x = q->a[q->tail++];
    if (q->tail == q->capacity)
        q->tail = 0;
    return x;
}

void debug(Queue *q) {
    for (int i = 0; i < q->capacity; ++i) {
        printf("%d ", q->a[i]);
    }
    puts("");
}

int main() {
    Queue q;
    initQueue(&q);
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
        } else if (strcmp(s, "END") == 0) {
            break;
        }
    }
    free(q.a);
    return 0;
}