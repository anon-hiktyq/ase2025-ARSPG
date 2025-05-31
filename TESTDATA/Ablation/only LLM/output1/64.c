
void foo(int y) {
    int x = 1;
    
    /*@ 
      loop invariant 0 <= x <= 11;
      loop invariant y == 10 - x;
      loop variant 11 - x;
    */
    while (x <= 10) {
        y = 10 - x;
        x = x + 1;
    }

    /*@ assert (y < 10); */
}
