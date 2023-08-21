#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define maxn 300500
char s[maxn];
int p[maxn];

int main(int argc, char *argv[]) {
    int n = strlen(argv[1]);
    int m = strlen(argv[2]);
    memcpy(s, argv[1], n);
    s[n] = '$';
    memcpy(s + n + 1, argv[2], m);
    int k = n + m + 1;
    for (int i = 1; i < k; i++) {
        int cur = p[i - 1];
        while (s[i] != s[cur] && cur > 0)
            cur = p[cur - 1];
        if (s[i] == s[cur])
            p[i] = cur + 1;
        if (p[i] == n)
            printf("%d ", i - 2 * n);
    }
    return 0;
}