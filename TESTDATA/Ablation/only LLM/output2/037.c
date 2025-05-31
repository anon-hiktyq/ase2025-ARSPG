
int unknown();
/*@
requires n > 0;
*/
void foo(int n) {
  int x = 0;
  int m = 0;
 
  /*@ 
    loop invariant 0 <= m && m < n && 0 <= x && x <= n;
    loop assigns x, m;
    loop variant n - x;
  */
  while (x < n) {
    if (unknown()) {
      m = x;
    }
    x = x + 1;
  }
  /*@ assert (n > 0) ==> (0 <= m && m < n); */
}
