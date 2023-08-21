#include <stdio.h>
#include <stdlib.h>

long long array[1000000];

int main(){
    int len, k;
    long long max_sum = 0, cur_sum = 0;
    scanf("%d", &len, &k);
    for (int i = 0; i < len; i++)
        scanf("%lld", &array[i]);
    scanf("%d", &k);

    for (int i = 0; i < k; i++)
        cur_sum += array[i];
    max_sum = cur_sum;
    for (int i = k; i < len; i++){
        cur_sum = cur_sum - array[i-k] + array[i];
        if (max_sum < cur_sum)
            max_sum = cur_sum;
    }
    printf("%lld", max_sum);
    return 0;
}