
void foo() {
    int x = 1;
    int y = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant  x == 1 + (y * (y - 1)) / 2 ;
      loop invariant  0 <= y <= 100000 ;
    */
    while (y < 100000) {
        x = x + y;
        y = y + 1;
    }

    /*@ assert x >= y; */
}
