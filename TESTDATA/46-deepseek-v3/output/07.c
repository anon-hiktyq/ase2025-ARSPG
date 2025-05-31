
int unknown();

/*@
requires n > 0;
*/
void foo(int n) {

  int i, a, b;
  i = 0; a = 0; b = 0;
  
  /*@
    loop invariant (\at(n, Pre) > 0) ==> ((0 < \at(n, Pre)) ==> (a + b == 3 * i));
    loop invariant (\at(n, Pre) > 0) ==> ((0 < \at(n, Pre)) ==> (i >= 0 && i <= n));
    loop invariant (\at(n, Pre) > 0) ==> ((!(0 < \at(n, Pre))) ==> ((b == 0)&&(a == 0)&&(i == 0)&&(n == \at(n, Pre))));
    loop invariant (\at(n, Pre) > 0) ==> (n == \at(n, Pre));
  */
  while( i < n ) {
    if(unknown()) {
      a = a + 1;
      b = b + 2;
    } else {
      a = a + 2;
      b = b + 1;
    }
    i = i + 1;
  }
  
  /*@ assert a + b == 3*n ; */
}
