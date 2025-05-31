
void foo(int y) {
    int x = -50;

    /*@ 
      loop invariant  (y >= \at(y, Pre)) || (x < 0) ; 
      loop invariant  (y >= \at(y, Pre)) || (y >= \at(y, Pre) + 50);
      loop invariant  (y >= \at(y, Pre) + (50 - (-50))) ; // Ensures y will be at least 0 after the loop
    */
    while (x < 0) {
        x = x + y;
        y = y + 1;
    }

    /*@ assert y > 0; */
}
