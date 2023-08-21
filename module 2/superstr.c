#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define maxn 11
#define maxk 300500
#define inf  1000000000

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x > y ? y : x;
}


int n;
char* s[maxn];
int  sz[maxn];
int   g[maxn][maxn];
int  dp[1 << maxn][maxn];

char buf[maxk];

int extra(int x, int y) {
    int ans = min(sz[x], sz[y]);
    for (; ans >= 0; --ans) {
        int f = 1;
        for (int i = 0; i < ans; ++i) {
            char c1 = s[x][sz[x] - ans + i];
            char c2 = s[y][i];
            if (c1 != c2) {
                f = 0;
                break;
            }
        }
        if (f)
            return ans;
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        sz[i] = strlen(buf);
        s[i] = (char*)malloc(sizeof(char) * sz[i]);
        memcpy(s[i], buf, sz[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g[i][j] = extra(i, j);
        }
    }

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!((mask >> i) & 1))
                    continue;
                if ((mask >> j) & 1)
                    continue;
                dp[mask | (1 << j)][j] = max(
                        dp[mask | (1 << j)][j],
                        dp[mask][i] + g[i][j]
                );
            }
        }
    }

    int e = 0;
    for (int i = 0; i < n; ++i) {
        e = max(e, dp[(1 << n) - 1][i]);
    }
    int s = 0;
    for (int i = 0; i < n; ++i) {
        s += sz[i];
    }
    int ans = s - e;
    printf("%d\n", ans);
    return 0;
}