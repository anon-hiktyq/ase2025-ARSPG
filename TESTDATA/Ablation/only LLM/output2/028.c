
int unknown();

void foo() {
  int x = 0;
  int y = 0;
  int n = 0;
 
  /*@ 
      loop invariant x == y;
      loop assigns x, y;
  */
  while(unknown()) {
      x++;
      y++;
  }
 
  int y0 = y;
  int x0 = x;
  /*@ 
      loop invariant y - x == y0 - x0;
      loop invariant x >= n;
      loop assigns x, y;
  */
  while(x != n) {
      x--;
      y--;
  }
  /*@ assert y == n; */
}
