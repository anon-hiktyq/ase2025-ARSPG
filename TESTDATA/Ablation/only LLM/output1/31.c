
void foo(int n, int v1, int v2, int v3) {
    int x = n;
    
    /*@ loop invariant x >= 1 && x <= n;
        loop variant x;
    */
    while (x > 1) {
        x = x - 1;
    }
    /*@ assert (x != 1) ==> (n < 1); */
}
