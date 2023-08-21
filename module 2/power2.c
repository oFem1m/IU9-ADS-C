#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 1000050

int n;
int a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int s = 0;
        for (int i = 0; i < 25; ++i) {
            if ((mask >> i) & 1)
                s += a[i];
        }
        for (int i = 0; i < 25; ++i) {
            ans += s == (1 << i);
        }
    }
    printf("%d", ans);
}