#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int strdiff(char *a, char *b);
int min(int a, int b);


int main(int argc, char **argv)
{
    char s1[1000], s2[1000];
    gets(s1);
    gets(s2);
    printf("%d\n", strdiff(s1, s2));

    return 0;
}

int min(int a, int b){
    if (a <= b)
        return a;
    else
        return b;
}


int strdiff(char *a, char *b)
{
    int counter = 0;
    if (strcmp(a, b) == 0)
        counter--;
    else{
        int len_a = strlen(a), len_b = strlen(b);
        int min_len = min(len_a, len_b);
        for (int i = 0; i <= min_len; i++){
            if (a[i] == b[i])
                counter += 8;
            else
                for (int j = 0; j < 8; j++){
                    if (((a[i] >> j) & 1) != (((b[i] >> j) & 1)))
                        return counter;
                    counter++;
                }
        }
    }
    return counter;
}