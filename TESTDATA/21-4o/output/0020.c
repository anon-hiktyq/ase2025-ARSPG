
#include "assert.h"

/*@
requires 0 <= n && n < 2;
requires 0 <= v;
*/
int foo(int n, int v) {
  int c1 = 4000;
  int c2 = 2000;
  int c3 = 10000;
  
  int i, k, j;

  k = 0;
  i = 0;

  /*@
    loop invariant  (0 <= \at(n, Pre) && \at(n, Pre) < 2 && 0 <= \at(v, Pre)) ==> ((0 < \at(n, Pre)) ==> (((k == 0)&&(i == 0)&&(c3 == 10000)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(n == \at(n, Pre))) || (0 <= i && i <= n))) ;
    loop invariant  (0 <= \at(n, Pre) && \at(n, Pre) < 2 && 0 <= \at(v, Pre)) ==> ((0 < \at(n, Pre)) ==> (((k == 0)&&(i == 0)&&(c3 == 10000)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(n == \at(n, Pre))) || (k == i * ((v == 0) ? c1 : ((v == 1) ? c2 : c3))))) ;
    loop invariant (0 <= \at(n, Pre) && \at(n, Pre) < 2 && 0 <= \at(v, Pre)) ==> ((!(0 < \at(n, Pre))) ==> ((k == 0)&&(i == 0)&&(c3 == 10000)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(n == \at(n, Pre))));
    loop invariant (0 <= \at(n, Pre) && \at(n, Pre) < 2 && 0 <= \at(v, Pre)) ==> (c3 == 10000);
    loop invariant (0 <= \at(n, Pre) && \at(n, Pre) < 2 && 0 <= \at(v, Pre)) ==> (c2 == 2000);
    loop invariant (0 <= \at(n, Pre) && \at(n, Pre) < 2 && 0 <= \at(v, Pre)) ==> (c1 == 4000);
    loop invariant (0 <= \at(n, Pre) && \at(n, Pre) < 2 && 0 <= \at(v, Pre)) ==> (v == \at(v, Pre));
    loop invariant (0 <= \at(n, Pre) && \at(n, Pre) < 2 && 0 <= \at(v, Pre)) ==> (n == \at(n, Pre));
  */
  while (i < n) {
    i++;
    if (v == 0)
      k += c1;
    else if (v == 1)
      k += c2;
    else
      k += c3;
  }

  j = 0;

  /*@
    loop invariant (0 <= j && j <= n);
    loop invariant (k >= n - j);
  */
  while (j < n) {
    /*@ assert k > 0; */
    j++;
    k--;
  }

  return 0;
}
