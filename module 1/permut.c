#include <stdio.h>

int main(int argc, char **argv){
    long long A[8], B[8];
    for (int i = 0; i < 8; i++)
        scanf("%lld", &A[i]);
    for (int i = 0; i < 8; i++)
        scanf("%lld", &B[i]);
    int comparsion = 1;
    for (int i = 0; i < 8; i++){
        int eq_check = 0, element;
        for (int j = i; j < 8; j++){
            if (A[i] == B[j]){
                element = B[i];
                B[i] = B[j];
                B[j] = element;
                eq_check = 1;
                break;
            }
        }
        if (eq_check == 0){
            printf("no");
            comparsion = 0;
            break;
        }
    }
    if (comparsion == 1)
        printf("yes");
    return 0;
}