int add2(int *a, int *b, int *r) {
    if (*a == *b) return *r;
    else if (*a == *r) return *b;
    else if (*b == *r) return *a;
    else return *a + *b + *r;
}