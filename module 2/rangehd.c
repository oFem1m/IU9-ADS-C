#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 1000050

int n;
char s[maxn];
char p[maxn];
int t[26][maxn];

void upd(int k, int i, int x) {
    for (; i < n; i |= i + 1)
        t[k][i] += x;
}

int get(int k, int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i)
        ans += t[k][i];
    return ans;
}


int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        s[i] -= 'a';
        upd(s[i], i, 1);
    }

    char c[10];
    while (1) {
        scanf("%s", c);
        if (c[0] == 'H') {
            int l, r;
            scanf("%d %d", &l, &r);
            int len = r - l + 1;
            int odd = 0;
            int f = 1;
            for (int i = 0; i < 26; ++i) {
                int x = get(i, r) - get(i, l - 1);
                odd += x % 2;
                if (len % 2 == 0 && odd > 0) {
                    puts("NO");
                    f = 0;
                    break;
                }
                if (len % 2 == 1 && odd > 1) {
                    puts("NO");
                    f = 0;
                    break;
                }
            }
            if (f)
                puts("YES");
        }
        if (c[0] == 'U') {
            int i;
            scanf("%d %s", &i, &p);
            int m = strlen(p);
            for (int j = i; j < i + m; ++j) {
                upd(s[j], j, -1);
            }
            for (int j = 0; j < m; ++j) {
                p[j] -= 'a';
                s[i + j] = p[j];
            }
            for (int j = i; j < i + m; ++j) {
                upd(s[j], j, 1);
            }
        }
        if (c[0] == 'E') {
            break;
        }
    }
}