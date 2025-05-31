
/*@
requires l > 0;
requires n > l;
*/
void foo(int n, int l) {
  int i, k;

  /*@
    loop invariant 1 <= k <= n;
    loop assigns k;
    loop variant n-k;
  */
  for (k = 1; k < n; k++) {
    i = l;
    /*@
      loop invariant l <= i <= n;
      loop assigns i;
      loop variant n-i;
    */
    for (i = l; i < n; i++) {
    }
  }

  /*@ assert \forall integer i; (l <= i < n) ==> (1 <= i); */
}
