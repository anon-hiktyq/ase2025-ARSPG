
int unknown();
/*@
requires n > 0;
*/
void foo(int n) {
  int x = 0;
  int m = 0;
 
    /*@
      loop invariant 0 <= x <= n; 
      loop invariant m <= x; 
      loop invariant m < n; 
      loop invariant (\at(n, Pre) > 0) ==> (n == \at(n, Pre));
      loop invariant (\at(n, Pre) > 0) ==> (0 <= m);
    */
    while (x < n) {
      if (unknown()) {
        m = x;
      }
      x = x + 1;
    }
    
  /*@ assert (n > 0) ==> (0 <= m && m < n); */
}
