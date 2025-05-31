
void foo(int y) {
    int x = -5000;

    /*@ 
      loop invariant  ((x == -5000) && (y == \at(y, Pre))) || (y >= 0) ;
      loop invariant  ((x == -5000) && (y == \at(y, Pre))) || (x == -5000 + k * \at(y, Pre) + k * (k - 1) / 2) ;
    */
    while (x < 0) {
        x  = x + y;
        y  = y + 1;
    }
    
    /*@ assert y > 0; */
}
