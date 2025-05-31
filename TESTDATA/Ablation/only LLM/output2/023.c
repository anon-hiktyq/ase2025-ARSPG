
/*@
requires n >= 0;
*/
void foo(int n) {
  int i, sum = 0;

  /*@
  loop invariant 0 <= i <= n;
  loop invariant sum == i * (i - 1) / 2;
  loop assigns i, sum;
  */
  for (i = 0; i < n; ++i) {
    sum = sum + i;
  }

  /*@ assert sum >= 0; */
}
