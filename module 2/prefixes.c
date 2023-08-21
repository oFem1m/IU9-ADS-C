#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define maxn 300500
#define inf  1000000000
#define p    37
#define mod  1000000007

typedef long long ll;

int max(int x, int y) {
    return x > y ? x : y;
}

int n;
char s[maxn];
int dp[maxn];

ll power[maxn];
ll h[maxn];

void build() {
    power[0] = 1;
    for (int i = 0; i <= n; ++i) {
        power[i + 1] = power[i] * p % mod;
    }
    for (int i = 0; i < n; ++i) {
        h[i + 1] = h[i] * p + (s[i] - 'a' + 1);
        h[i + 1] %= mod;
    }
}

int get(int l, int r) {
    ll big = h[r];
    ll small = h[l];
    int ans = h[r] - small * power[r - l] % mod;
    if (ans < 0)
        ans += mod;
    return ans;
}

int main(int argc, char *argv[]) {
    n = strlen(argv[1]);
    memcpy(s, argv[1], n);
    build();
    for (int i = 1; i <= n; ++i) {
        int pr = get(0, i);
        for (int j = i, k = 1; j <= n; j += i, ++k) {
            if (pr == get(j - i, j))
                dp[j] = max(dp[j], k);
            else
                break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dp[i] == 1)
            continue;
        printf("%d %d\n", i, dp[i]);
    }
}