#include <stdio.h>

int main(int argc, char **argv){
    unsigned long long x, fibonacci[100], result[100];
    for(int i = 0; i < 100; i++)
        result[i] = 0;
    int number = 2;
    scanf("%llu", &x);
    if (x == 0) printf("%d", 0);
    else{
        fibonacci[0] = fibonacci[1] = 1;
        while ((fibonacci[number-2] + fibonacci[number-1]) <= x){
            fibonacci[number] = fibonacci[number-2] + fibonacci[number-1];
            number++;
        }
        int max_fib = number-1;
        result[max_fib] = 1;
        x -= fibonacci[max_fib];
        while (x > 0){
            int i = number-1;
            while (fibonacci[i] > x) i--;
            x -= fibonacci[i];
            result[i] = 1;
            number = i;
        }

        for (int i = max_fib; i >= 1; i--)
            printf("%llu", result[i]);
    }
    return 0;
}
