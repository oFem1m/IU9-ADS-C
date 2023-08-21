#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define maxn 1500000
#define inf  1000000000

typedef struct Node Node;
typedef struct Heap Heap;

struct Node {
    int val;
    int seq;
};

struct Heap {
    Node *h;
    int m;
};

void sift_up(Heap *heap) {
    int i = heap->m - 1;
    while (heap->h[i].val < heap->h[(i - 1) / 2].val) {
        int p = (i - 1) / 2;
        Node t = heap->h[i];
        heap->h[i] = heap->h[p];
        heap->h[p] = t;
        i = p;
    }
}

void sift_down(Heap *heap) {
    int i = 0;
    while (2 * i + 1 < heap->m) {
        int lc = i * 2 + 1;
        int rc = i * 2 + 2;
        int c = lc;
        if (rc < heap->m && heap->h[rc].val < heap->h[lc].val)
            c = rc;
        if (heap->h[i].val <= heap->h[c].val)
            break;
        Node t = heap->h[i];
        heap->h[i] = heap->h[c];
        heap->h[c] = t;
        i = c;
    }
}

void add(Heap *heap, Node x) {
    heap->h[heap->m++] = x;
    sift_up(heap);
}

Node pop_min(Heap *heap) {
    Node mn = heap->h[0];
    heap->h[0] = heap->h[--heap->m];
    sift_down(heap);
    return mn;
}

int main() {
    int n;
    scanf("%d", &n);

    Heap heap;
    heap.m = 0;
    heap.h = (Node *) malloc(sizeof(Node *) * n);

    int *s = (int *) malloc(sizeof(int) * n);
    int *p = (int *) malloc(sizeof(int) * n);
    int **a = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < n; ++i) {
        a[i] = (int *) malloc(sizeof(int) * s[i]);
        p[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s[i]; ++j) {
            scanf("%d", &a[i][j]);
        }
        Node node;
        node.seq = i;
        node.val = a[i][0];

        add(&heap, node);
    }
    while (heap.m > 0) {
        Node min = pop_min(&heap);
        if (p[min.seq] != s[min.seq]) {
            Node next;
            next.val = a[min.seq][p[min.seq]++];
            next.seq = min.seq;
            add(&heap, next);
        }
        printf("%d ", min.val);
    }
    free(heap.h);
    free(s);
    free(p);
    for (int i = 0; i < n; ++i) {
        free(a[i]);
    }
    free(a);
    return 0;
}