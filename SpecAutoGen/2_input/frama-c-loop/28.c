int fun28(int x, int y , int *r) {
    *r = x;
    int d = 0;

    while (*r >= y) {
        *r = *r - y;
        d = d + 1;
    }
    return d;
}

int main28() {
    int a = 3;
    int num = fun28(1, 2, &a);
    //@ assert a == 1;
    //@ assert num == 0;
    return 0;
}