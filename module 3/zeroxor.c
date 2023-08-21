#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int *l, int *r, int *s) {
    if (r - l == 1) {
        return;
    }
    int *m = l + (r - l) / 2;
    sort(l, m, s);
    sort(m, r, s);
    int *i = l;
    int *j = m;
    int k = 0;
    while (i < m && j < r) {
        if (*i <= *j) {
            s[k++] = *i++;
        } else {
            s[k++] = *j++;
        }
    }
    while (i < m)
        s[k++] = *i++;
    while (j < r)
        s[k++] = *j++;
    for (int i = 0; l != r; ++l, ++i)
        *l = s[i];
}

int *bin_search(int *l, int *r, int x) {
    while (r - l > 1) {
        int *m = l + (r - l) / 2;
        if (*m > x) {
            r = m;
        } else {
            l = m;
        }
    }
    return l;
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *) malloc(sizeof(int) * n);
    int *b = (int *) malloc(sizeof(int) * (n + 1));
    int *c = (int *) malloc(sizeof(int) * (n + 1));
    int *s = (int *) malloc(sizeof(int) * (n + 1));
    memset(c, 0, sizeof(int) * (n + 1));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cur ^= a[i];
        b[i] = cur;
    }
    b[n] = 0;
    sort(b, b + n + 1, s);

    long long ans = 0;
    cur = 0;
    c[bin_search(b, b + n + 1, 0) - b] = 1;
    for (int i = 0; i < n; ++i) {
        cur ^= a[i];
        int j = bin_search(b, b + n + 1, cur) - b;
        ans += c[j];
        c[j] += 1;
    }
    printf("%lld\n", ans);
    free(a);
    free(b);
    free(c);
    free(s);
    return 0;
}