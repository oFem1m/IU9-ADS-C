unsigned long peak(unsigned long nel,
                   int (*less)(unsigned long i, unsigned long j)){
    if (nel <= 1) return 0;
    else if ((less(1, 0) == 1) ||  (less(1, 0) == less(0, 1)))
        return 0;
    else if ((less(nel-2, nel-1) == 1) || (less(nel-1, nel-2) == less(nel-2, nel-1)))
        return nel-1;
    else
        for(unsigned long i = 1; i < nel-1; i++)
            if (((less(i-1, i) == 1) || (less(i-1, i) == less(i, i-1))) &&
                ((less(i+1, i) == 1) || (less(i+1, i) == less(i, i+1))))
                return i;
}