
void foo() {
    int x = 1;
    int y = 0;

    /*@ 
        loop invariant y <= 1000;
        loop invariant x >= y;
        loop invariant x == y * (y - 1) / 2 + 1;
        loop assigns x, y;
        loop variant 1000 - y;
    */
    while (y < 1000 ) {
        x = x + y;
        y = y + 1;
    }
    /*@ assert x >= y; */
}
