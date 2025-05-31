
void foo(int n, int y) {
    int x = 1;
    /*@ 
        loop invariant 0 < x <= n + 1;
        loop invariant y == n - x + 1;
        loop assigns x, y;
        loop variant n - x;
    */
    while (x <= n) {
        y = n - x;
        x = x + 1;
    }
    /*@ assert (n > 0) ==> (y <= n); */
}
