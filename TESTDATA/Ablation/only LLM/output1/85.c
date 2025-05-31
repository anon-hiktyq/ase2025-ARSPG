
void foo(int y,int z1,int z2,int z3) {
    int x = -15000;
    int y0 = y;
    
    /*@ 
      loop invariant x + y * (y - y0 - 1) >= 0;
      loop assigns x, y;
      loop variant -x;
    */
    while (x < 0) {
        x = x + y;
        y = y + 1;
    }
    /*@ assert y > 0; */
}
