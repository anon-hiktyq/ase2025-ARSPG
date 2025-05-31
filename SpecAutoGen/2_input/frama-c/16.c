int incr_a_by_b(int* a, int * b){
    *a += *b;
    return *a;
}

// write a test
void main16() {
    int a = 10;
    int b = 20;
    incr_a_by_b(&a, &b);
    //@ assert a == 30;
    //@ assert b == 20;
}