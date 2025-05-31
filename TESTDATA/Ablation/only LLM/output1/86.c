
void foo(int y, int z1, int z2, int z3) {
    int x = -50;
  
    /*@ 
      loop invariant x < y * (y - \old(y)) - 50;
      loop invariant x < 0;
      loop assigns x, y;
      loop variant 0 - x;
    */
    while (x < 0) {
        x = x + y;
        y = y + 1;
    }
    /*@ assert y > 0; */
}
