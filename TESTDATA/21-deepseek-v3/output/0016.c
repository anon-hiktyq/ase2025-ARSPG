
/*@
requires n > 0;
*/
void foo(int n) {
 
  int i = 0;
  int k = 0;
  
  /* >>> LOOP INVARIANT TO FILL <<< */
  /*@
    loop invariant (\at(n, Pre) > 0) ==> ((0 < \at(n, Pre)) ==> (((k == 0)&&(i == 0)&&(n == \at(n, Pre))) || (k == i))) ;
    loop invariant (\at(n, Pre) > 0) ==> ((0 < \at(n, Pre)) ==> (((k == 0)&&(i == 0)&&(n == \at(n, Pre))) || (0 <= i <= n))) ;
    loop invariant (\at(n, Pre) > 0) ==> ((!(0 < \at(n, Pre))) ==> ((k == 0)&&(i == 0)&&(n == \at(n, Pre))));
    loop invariant (\at(n, Pre) > 0) ==> (n == \at(n, Pre));
  */
  while( i < n ) {
    i++;
    k++;
  }
  
  int j = 0;
 
  /* >>> LOOP INVARIANT TO FILL <<< */
  /*@
    loop invariant 0 <= j <= n && k == n - j;
  */
  while( j < n ) {
    /*@ assert k > 0;*/
    j++;
    k--;
  }
}
