
void foo(int y) {
    int x = -5000;
    
    /*@ 
      loop invariant x + y * (y - \old(y) - 1) >= -5000;
      loop invariant y > \old(y);
      loop assigns x, y;
      loop variant 5000 + x;
    */
    while (x < 0) {
        x = x + y;
        y = y + 1;
    }
    /*@ assert y > 0; */
}
