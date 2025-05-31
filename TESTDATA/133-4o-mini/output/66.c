
void foo(int y) {
    int x = 1;
    
    /* Pre-condition of the loop: (x == 1) * (y == \at(y, Pre)) */
    
    /*@
      loop invariant  ((x == 1) && (y == \at(y, Pre))) || (1 <= x <= 101 && y == 100 - (x - 1));
      loop invariant  ((x == 1) && (y == \at(y, Pre))) || (x >= 1 && x <= 101);
    */
    while (x <= 100) {
        y = 100 - x;
        x = x + 1;
    }
    
    /*@ assert (y < 100); */
}
