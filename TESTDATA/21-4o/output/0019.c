
#include <limits.h>

/*@
requires n <= INT_MAX;
*/
void foo(int n) {
  int i,k;
  k = n;
  i = 0;

  /* >>> LOOP INVARIANT TO FILL <<< */
  /*@
    loop invariant  (\at(n, Pre) <= INT_MAX) ==> (n == \at(n, Pre));
  */
  while( i < n ) {
    k--;
    i = i + 2;
  }

  int j = 0;
  
  /* >>> LOOP INVARIANT TO FILL <<< */
  /*@
    loop invariant  (0 >= n && (\at(n, Pre) <= INT_MAX ==> n == \at(n, Pre)) && \at(n, Pre) <= INT_MAX) ==> ((0 < n/2) ==> (((j == 0)&&(k == \at(n, Pre))&&(i == 0)) || (j <= n/2 && k + j == \at(n, Pre)))) ;
  */
  while( j < n/2 ) {
    /*@ assert k > 0; */
    k--;
    j++;
  }
}
