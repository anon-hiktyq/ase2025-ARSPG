
void foo(int x, int y) {
    /*@ 
      requires x >= 0;
      requires y >= 0;
      assigns x, y;
      ensures y == \old(y) - \old(x);
    */
    int i = x;
    int j = y;

    /*@ 
      loop invariant i - j == x - y;
      loop invariant 0 <= x <= i;
      loop assigns x, y;
      loop variant x;
    */
    while (x != 0) {
        x = x - 1;
        y = y - 1;
    }
}
