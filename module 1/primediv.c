#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv){
    int number, sieve[65537], primes[65536];
    scanf("%d", &number);
    number = abs(number);
    for (int i = 1; i < 65537; i++){
        sieve[i] = 1;
    }
    sieve[1] = 0;
    for (int i = 2; i <= 256; i++){
        int j = i;
        while ((j + i) < 65537){
            sieve[j+i] = 0;
            j += i;
        }
    }
    int cur_iter = 0;
    for (int i = 1; i < 65537; i++){
        if (sieve[i] == 1){
            primes[cur_iter] = i;
            cur_iter++;
        }
    }

    int max_prime_div = 0;
    for (int i = cur_iter - 1; i >= 0; i--){
        if (number % primes[i] == 0){
            max_prime_div = primes[i];
            break;
        }
    }
    int div_check = 1;
    while (div_check > 0 && number > 0){
        div_check = 0;
        for (int i = 0; i < cur_iter; i++){
            if (number % primes[i] == 0){
                number /= primes[i];
                div_check = 1;
            }
        }
    }
    if (number >= max_prime_div)
        printf("%d", number);
    else
        printf("%d", max_prime_div);
    return 0;
}