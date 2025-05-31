
void foo(int n, int y, int v1, int v2, int v3) {
    int x = 1;

    /*@ 
        loop invariant 1 <= x <= n + 1;
        loop invariant y == n - x;
        loop assigns x, y;
        loop variant n - x;
    */
    while (x <= n) {
        y = n - x;
        x = x + 1;
    }

    /*@ assert (n > 0) ==> (y <= n); */
}
