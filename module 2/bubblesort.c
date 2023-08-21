#include  <stdio.h>

int A[] = {5, 2, 4, 3, 1};

void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j));

int compare(unsigned long i, unsigned long j);

void swap(unsigned long i, unsigned long j);

int main(int argc, char **argv) {
    bubblesort(5, compare, swap);
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

void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j)) {
    int left = 0, right = nel - 1;
    int swap_checker = 1;
    while ((left < right) && swap_checker > 0) {
        swap_checker = 0;
        for (int i = left; i < right; i++) {
            if (compare(i, i + 1) == 1) {
                swap(i, i + 1);
                swap_checker = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (compare(i - 1, i) == 1) {
                swap(i - 1, i);
                swap_checker = 1;
            }
        }
        left++;
    }
}