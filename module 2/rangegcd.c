#include <stdio.h>
#include <stdlib.h>

#define maxn 300500
#define logn 19

int n;
int a[maxn];
int s[logn][maxn];

int lg2(int x) {
    return 31 - __builtin_clz(x);
}

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void build() {
    for (int i = 0; i < n; ++i) {
        s[0][i] = a[i];
    }
    for (int k = 1; k < logn; ++k) {
        for (int i = 0; i + (1 << (k - 1)) < n; ++i) {
            s[k][i] = gcd(s[k - 1][i], s[k - 1][i + (1 << (k - 1))]);
        }
    }
}

int get(int l, int r) {
    int len = r - l;
    int k = lg2(len);
    return gcd(s[k][l], s[k][r - (1 << k)]);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] < 0)
            a[i] = -a[i];
    }
    build();
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        r++;
        int ans = get(l, r);
        printf("%d\n", ans);
    }
    return 0;
}