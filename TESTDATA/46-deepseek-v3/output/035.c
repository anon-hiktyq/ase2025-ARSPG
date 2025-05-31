
/*@
requires n > 0;
*/
void foo(int n) {
  int x= 0;
  
  /*@
    loop invariant 0 <= x <= n;
    loop invariant x <= n;
    loop invariant \at(n, Pre) == n;
    loop assigns x;
   */
  while(x<n) {
    x++;
  }
  
  /*@ assert (n > 0) ==> (x == n); */
}
