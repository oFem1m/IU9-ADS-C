#include <stdio.h>

int main(int argc, char **argv){
    long long x, n, coefficient, polynom, derivative;
    scanf("%lld %lld %lld", &n, &x, &polynom);
    derivative = polynom * n;
    for (int i = 1; i <= n; i++){
        scanf("%lld", &coefficient);
        polynom = (polynom * x + coefficient);
        if (i < n)
            derivative = (derivative * x + coefficient * (n-i));
    }
    printf("%lld %lld", polynom, derivative);
    return 0;
}
