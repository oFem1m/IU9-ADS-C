#include <stdio.h>
#include <stdlib.h>

#define maxn 1000500

int n;
int a[maxn];
int t[maxn];

void upd(int i, int x) {
    for (; i < n; i |= i + 1)
        t[i] += x;
}

int get(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i)
        ans += t[i];
    return ans;
}

int is_peak(int i) {
    int f1 = 1;
    int f2 = 1;
    if (i - 1 >= 0)
        f1 &= a[i] >= a[i - 1];
    if (i + 1 < n)
        f2 &= a[i] >= a[i + 1];
    return f1 & f2;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (is_peak(i))
            upd(i, 1);
    }
    char c[10];
    while (1) {
        scanf("%s", c);
        if (c[0] == 'P') {
            int l, r;
            scanf("%d %d", &l, &r);
            int ans = get(r) - get(l - 1);
            printf("%d\n", ans);
        }
        if (c[0] == 'U') {
            int i, v;
            scanf("%d %d", &i, &v);
            if (i - 1 >= 0 && is_peak(i - 1))
                upd(i - 1, -1);
            if (is_peak(i))
                upd(i, -1);
            if (i + 1 < n && is_peak(i + 1))
                upd(i + 1, -1);
            a[i] = v;
            if (i - 1 >= 0 && is_peak(i - 1))
                upd(i - 1, 1);
            if (is_peak(i))
                upd(i, 1);
            if (i + 1 < n && is_peak(i + 1))
                upd(i + 1, 1);
        }
        if (c[0] == 'E') {
            break;
        }
    }
}