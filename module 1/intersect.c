#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
    int A = 0, num_A, B = 0, num_B, element, intersection;
    scanf("%d", &num_A);
    for (int i = 0; i < num_A; i++){
        scanf("%d", &element);
        A = A | 1 << element;
    }
    scanf("%d", &num_B);
    for (int i = 0; i < num_B; i++){
        scanf("%d", &element);
        B = B | 1 << element;
    }
    intersection = A & B;

    for (int i = 0; i < 32; i++)
        if ((intersection & (1 << i)) != 0)
            printf("%d ", i);


    return 0;
}