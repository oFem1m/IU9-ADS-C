#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define maxn 500500
#define inf  1000000000

typedef long long ll;

int min(int x, int y) {
    return x > y ? y : x;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int n, m, k;
char s[maxn];
int z[maxn];

void zFunction() {
    int l = 0, r = 0;
    for (int i = 1; i < k; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < k && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
}

int main(int argc, char *argv[]) {
    n = strlen(argv[1]);
    m = strlen(argv[2]);
    k = n + m + 1;


    memcpy(s, argv[1], n);
    s[n] = '$';
    memcpy(s + n + 1, argv[2], m);
    zFunction();
    for (int i = n + 1; i < k; ++i) {
        z[i] = max(z[i - 1] - 1, z[i]);
        if (z[i] == 0) {
            puts("no");
            return 0;
        }
    }
    puts("yes");
    return 0;
}