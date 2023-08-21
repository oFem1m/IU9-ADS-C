#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define maxn 500500

void swap(int* x, int* y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int rnd() {
    static unsigned int X = 0xAB0BA420;
    return (X *= 3) >> 1;
}

int n, m;
int arr[maxn];

void selection_sort(int l, int r) {
    for (int i = l; i < r; ++i) {
        int mini = i;
        for (int j = i + 1; j < r; ++j) {
            if (arr[j] < arr[mini])
                mini = j;
        }
        swap(&arr[i], &arr[mini]);
    }
}

void sort(int l, int r) {
    if (r - l <= m) {
        selection_sort(l, r);
        return;
    }
    int piv = arr[l + rnd() % (r - l)];
    int less = 0;
    int equal = 0;
    int greater = 0;
    for (int i = l; i < r; ++i) {
        if (arr[i] < piv)
            less++;
        else if (arr[i] == piv)
            equal++;
        else
            greater++;
    }

    int* buf = (int*)malloc(sizeof(int) * (r - l));
    greater += equal += less;
    for (int i = l; i < r; ++i) {
        if (arr[i] < piv)
            buf[--less] = arr[i];
        else if (arr[i] == piv)
            buf[--equal] = arr[i];
        else
            buf[--greater] = arr[i];
    }
    memcpy(arr + l, buf, sizeof(int) * (r - l));
    free(buf);
    sort(l, l + equal);
    sort(l + greater, r);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(0, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    puts("");
    return 0;
}