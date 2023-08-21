#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define maxn 500500
#define inf  1000000000

int max(int x, int y) {
    return x > y ? x : y;
}

typedef struct Node Node;
typedef struct Heap1 Heap1;
typedef struct Heap2 Heap2;

struct Node {
    int v;
    int s;
};

struct Heap1 {
    int *h1;
    int m1;
};

struct Heap2 {
    Node *h2;
    int m2;
};

// first heap
void sift_up1(Heap1 *heap) {
    int i = heap->m1 - 1;
    while (heap->h1[i] < heap->h1[(i - 1) / 2]) {
        int p = (i - 1) / 2;
        int t = heap->h1[i];
        heap->h1[i] = heap->h1[p];
        heap->h1[p] = t;
        i = p;
    }
}

void sift_down1(Heap1 *heap) {
    int i = 0;
    while (2 * i + 1 < heap->m1) {
        int lc = i * 2 + 1;
        int rc = i * 2 + 2;
        int c = lc;
        if (rc < heap->m1 && heap->h1[rc] < heap->h1[lc])
            c = rc;
        if (heap->h1[i] <= heap->h1[c])
            break;
        int t = heap->h1[i];
        heap->h1[i] = heap->h1[c];
        heap->h1[c] = t;
        i = c;
    }
}

void add1(Heap1 *heap, int x) {
    heap->h1[heap->m1++] = x;
    sift_up1(heap);
}

int pop_min1(Heap1 *heap) {
    int mn = heap->h1[0];
    heap->h1[0] = heap->h1[--(heap->m1)];
    sift_down1(heap);
    return mn;
}

// second heap
void sift_up2(Heap2 *heap) {
    int i = heap->m2 - 1;
    while (heap->h2[i].v < heap->h2[(i - 1) / 2].v) {
        int p = (i - 1) / 2;
        Node t = heap->h2[i];
        heap->h2[i] = heap->h2[p];
        heap->h2[p] = t;
        i = p;
    }
}

void sift_down2(Heap2 *heap) {
    int i = 0;
    while (2 * i + 1 < heap->m2) {
        int lc = i * 2 + 1;
        int rc = i * 2 + 2;
        int c = lc;
        if (rc < heap->m2 && heap->h2[rc].v < heap->h2[lc].v)
            c = rc;
        if (heap->h2[i].v <= heap->h2[c].v)
            break;
        Node t = heap->h2[i];
        heap->h2[i] = heap->h2[c];
        heap->h2[c] = t;
        i = c;
    }
}

void add2(Heap2 *heap, Node x) {
    heap->h2[heap->m2++] = x;
    sift_up2(heap);
}

Node pop_min2(Heap2 *heap) {
    Node mn = heap->h2[0];
    heap->h2[0] = heap->h2[--(heap->m2)];
    sift_down2(heap);
    return mn;
}

int main() {
    int n, m;
    scanf("%d", &n);

    Heap1 heap1;
    heap1.m1 = 0;
    heap1.h1 = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n; ++i) {
        add1(&heap1, i);
    }
    scanf("%d", &m);

    Heap2 heap2;
    heap2.m2 = 0;
    heap2.h2 = (Node *) malloc(sizeof(Node) * m);

    int *t1 = (int *) malloc(sizeof(int) * m);
    int *t2 = (int *) malloc(sizeof(int) * m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &t1[i], &t2[i]);
    }

    int k = 0;
    int t = 0;
    while (k < m || heap2.m2 != 0) {
        int ta = inf;
        int tb = inf;
        if (k < m && heap1.m1 != 0) {
            ta = t1[k];
        }
        if (heap2.m2 != 0) {
            tb = heap2.h2[0].v;
        }
        if (tb <= ta) {
            t = tb;
            int s = pop_min2(&heap2).s;
            add1(&heap1, s);
        } else {
            t = max(t, ta);
            int s = pop_min1(&heap1);
            Node node;
            node.v = t + t2[k++];
            node.s = s;
            add2(&heap2, node);
        }
    }
    printf("%d", t);
    free(t1);
    free(t2);
    free(heap1.h1);
    free(heap2.h2);
    return 0;
}