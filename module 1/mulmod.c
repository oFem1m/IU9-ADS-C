#include <stdio.h>

void bin_llu(unsigned long long number, int *pResult);

int main(int argc, char **argv){
    unsigned long long a , b, m;
    int b_bin[64];
    scanf("%llu %llu %llu", &a, &b, &m);
    for (int i = 0; i < 64; i++)
        b_bin[i] = 0;
    int *pB_bin = b_bin;
    bin_llu(b, pB_bin);
    unsigned long long result = a * b_bin[0];
    for (int i = 0; i < 64; i++){
        result = ((result * 2) % m + (a * b_bin[i]) % m) % m;
    }
    printf("%llu", result);
    return 0;
}

void bin_llu(unsigned long long number, int *pResult){
    int i = 63;
    while (number > 0){
        pResult[i] = (number % 2);
        number /= 2;
        i--;
    }
}