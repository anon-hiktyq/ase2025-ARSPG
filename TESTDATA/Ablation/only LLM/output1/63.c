
void foo(int y) {
    int x = 1;

    /*@ 
    loop invariant 0 <= y <= 9 && x >= 1 && x <= 11;
    */
    while (x <= 10) {
        y = 10 - x;
        x = x + 1;
    }

    /*@ assert (y >= 0); */
}
