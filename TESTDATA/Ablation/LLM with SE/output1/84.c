
void foo(int y) {
    int x = -50;
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant  ((x == -50)&&(y == \at(y, Pre))) || (y > \at(y, Pre)) ;
      loop invariant  ((x == -50)&&(y == \at(y, Pre))) || (x >= -50) ;
    */
    while (x < 0) {
        x = x + y;
        y = y + 1;
    }
    /*@ assert y > 0; */
}
