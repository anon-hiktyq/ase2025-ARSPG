int add13(int *a, int *b, int *r) {
    return *a + *a + *b;
}

int main13() {
    int a = 24;
    int b = 32;
    int r = 12;
    int x;

    x = add13(&a, &b, &r) ;
    //@ assert x == a + b + r;
    //@ assert x == 68 ;

    x = add13(&a, &a, &a) ;
    //@ assert x == a + a + a;
    //@ assert x == 72 ;
    return 0;
}