
void foo(int y) {
    int x = 1;
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant  ((x == 1)&&(y == \at(y, Pre))) || (y >= 0) ;
    */
    while (x <= 10) {
        y = 10 - x;
        x = x + 1;
    }
    
    /*@ assert (y >= 0); */
}
