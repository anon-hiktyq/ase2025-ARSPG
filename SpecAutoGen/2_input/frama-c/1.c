

int abs(int val) {
    if(val < 0) return -val;
    return val;
}

void foo1(int a) {
    int b = abs(-42);
    //@ assert b == 42;
    int c = abs(42);
    //@ assert c == 42;
    int d = abs(a);
    int e = abs(-997);

}
