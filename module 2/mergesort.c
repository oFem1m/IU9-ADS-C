#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define maxn 300500
#define inf  1000000000

typedef struct Node Node;

int n;
int a[maxn];
int s[maxn];

void insertion_sort(int l, int r) {
    for (int i = l + 1; i < r; ++i) {
        for (int j = i - 1; j >= l && abs(a[j + 1]) < abs(a[j]); --j) {
            int t = a[j + 1];
            a[j + 1] = a[j];
            a[j] = t;
        }
    }
}

void sort(int l, int r) {
    if (r - l <= 5) {
        insertion_sort(l, r);
        return;
    }
    int m = (r + l) / 2;
    sort(l, m);
    sort(m, r);
    int i = l;
    int j = m;
    int k = 0;
    while (i < m && j < r) {
        if (abs(a[i]) <= abs(a[j])) {
            s[k++] = a[i++];
        } else {
            s[k++] = a[j++];
        }
    }
    while (i < m)
        s[k++] = a[i++];
    while (j < r)
        s[k++] = a[j++];
    for (int i = 0; l < r; ++l, ++i)
        a[l] = s[i];
}


int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(0, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}