#include  <stdio.h>

int A[] = {5, 2, 4, 3, 1};

void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j));

int compare(unsigned long i, unsigned long j);

void swap(unsigned long i, unsigned long j);

int main(int argc, char **argv) {
    shellsort(5, compare, swap);
    for (int i = 0; i < 5; i++) printf("%d ", A[i]);
    return 0;
}

int compare(unsigned long i, unsigned long j) {
    if (A[i] < A[j]) return -1;
    else if (A[i] == A[j]) return 0;
    else return 1;
}

void swap(unsigned long i, unsigned long j) {
    int element = A[i];
    A[i] = A[j];
    A[j] = element;
}

void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j)) {
    unsigned long fib[46], fib_cur = 1, fib_prev = 1;
    int i = 2, counter = 2;
    fib[0] = fib[1] = 1;
    while ((fib_prev + fib_cur) <= nel) {
        fib[i] = fib_prev + fib_cur;
        fib_prev = fib_cur;
        fib_cur = fib[i];
        i++;
        counter++;
    }

    for (int k = counter - 1; k > 0; k--)
        for (unsigned long i = fib[k]; i < nel; ++i)
            for (int j = i - fib[k]; j >= 0 && (compare(j, j + fib[k]) == 1); j -= fib[k]) swap(j, j + fib[k]);
}
