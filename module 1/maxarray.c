int maxarray(void *base, unsigned long nel, unsigned long width,
             int (*compare)(void *a, void *b)){
    int max_id = 0, i;
    char *element1, *element2;
    for (i = 1; i < nel; i++) {
        element1 = (char *)base + max_id * width;
        element2 = (char *)base + i * width;
        if (compare(element1, element2) < 0)
            max_id = i;
    }
    return max_id;
}