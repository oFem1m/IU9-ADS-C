unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    int check = 0;
    unsigned long l = 0, r = nel - 1, m;
    while ((l <= r) && (check != 1)){
        m = (l + r) / 2;
        if (compare(m) == 0)
            check = 1;
        if (compare(m) == 1)
            r = m - 1;
        else
            l = m + 1;
    }
    if (check == 1)
        return m;
    else
        return nel;
}