int fun7(int x, int y , int *r) {
    *r = x;
    int d = 0;

    while (*r >= y) {
        *r = *r - y;
        d = d + 1;
    }
    return d;
}