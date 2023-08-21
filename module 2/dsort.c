#include <stdio.h>
#include <string.h>

void distribsort(char *str);

int a[123] = {0};
char s[1000005];

int main(int argc, char **argv) {
    scanf("%s", s);
    distribsort(s);
    return 0;
}

void distribsort(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) a[(int) str[i]] += 1;

    int k = 0;
    for (int i = 97; i < 123; i++)
        for (int j = 1; j <= a[i]; j++) s[k++] = i;
    printf("%s", s);
}