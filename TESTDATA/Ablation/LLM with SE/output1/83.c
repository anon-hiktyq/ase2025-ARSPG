
void foo(int y) {
    int x = -5000;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant  ((x == -5000)&&(y == \at(y, Pre))) || (y > \at(y, Pre)) ;
      loop invariant  ((x == -5000)&&(y == \at(y, Pre))) || (x >= -5000 + (\at(y, Pre) * (\at(y, Pre) + 1) / 2)) ;
    */
    while (x < 0) {
        x  = x + y;
        y  = y + 1;
    }

    /*@ assert y > 0; */
}
