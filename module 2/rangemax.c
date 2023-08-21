#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define maxn 1000500
#define inf  1000000000

int max(int x, int y) {
    return x > y ? x : y;
}

int n;
int a[maxn];
int t[4 * maxn];

void build(int id, int l, int r) {
    if (r - l == 1) {
        t[id] = a[l];
        return;
    }
    int m = (r + l) / 2;
    build(2 * id + 1, l, m);
    build(2 * id + 2, m, r);
    t[id] = max(t[id * 2 + 1], t[id * 2 + 2]);
}

int get(int id, int l, int r, int lq, int rq) {
    if (lq <= l && r <= rq)
        return t[id];
    if (rq <= l || r <= lq)
        return -inf;
    int m = (r + l) / 2;
    int lc = get(id * 2 + 1, l, m, lq, rq);
    int rc = get(id * 2 + 2, m, r, lq, rq);
    return max(lc, rc);
}

void upd(int id, int l, int r, int i, int v) {
    if (r - l == 1) {
        t[id] = v;
        return;
    }
    int m = (r + l) / 2;
    if (i < m) {
        upd(id * 2 + 1, l, m, i, v);
    } else {
        upd(id * 2 + 2, m, r, i, v);
    }
    t[id] = max(t[id * 2 + 1], t[id * 2 + 2]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    build(0, 0, n);;

    char s[10];
    while (1) {
        scanf("%s", s);
        if (s[0] == 'M') {
            int l, r;
            scanf("%d %d", &l, &r);
            r++;
            int ans = get(0, 0, n, l, r);
            printf("%d\n", ans);
        }
        if (s[0] == 'U') {
            int i, v;
            scanf("%d %d", &i, &v);
            upd(0, 0, n, i, v);
        }
        if (s[0] == 'E') {
            break;
        }
    }
    return 0;
}