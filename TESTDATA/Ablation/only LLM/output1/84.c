
void foo(int y) {
    int x = -50;
    /*@ 
      loop invariant x < 0 ==> y > 0;
      loop invariant x >= -50;
      loop invariant x <= y * (y - 1) / 2 - 50;
      loop variant -x; 
    */
    while (x < 0) {
      x = x + y;
      y = y + 1;
    }
    /*@ assert y > 0; */
}
