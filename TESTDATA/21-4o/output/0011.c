
#include <limits.h>

/*@
requires INT_MIN < n0 && n0 < INT_MAX;
requires INT_MIN < n1 && n1 < INT_MAX;
*/
void foon(int n0, int n1) {

  int i0 = 0;
  int k = 0;

  /* >>> LOOP INVARIANT TO FILL <<< */

  /*@
    loop invariant  (INT_MIN < \at(n0, Pre) && \at(n0, Pre) < INT_MAX && INT_MIN < \at(n1, Pre) && \at(n1, Pre) < INT_MAX) ==> ((0 < \at(n0, Pre)) ==> (((k == 0)&&(i0 == 0)&&(n1 == \at(n1, Pre))&&(n0 == \at(n0, Pre))) || (i0 <= n0 && k == i0))) ;
    loop invariant  (INT_MIN < \at(n0, Pre) && \at(n0, Pre) < INT_MAX && INT_MIN < \at(n1, Pre) && \at(n1, Pre) < INT_MAX) ==> ((0 < \at(n0, Pre)) ==> (((k == 0)&&(i0 == 0)&&(n1 == \at(n1, Pre))&&(n0 == \at(n0, Pre))) || (i0 <= n0 && k == i0))) ;
    loop invariant (INT_MIN < \at(n0, Pre) && \at(n0, Pre) < INT_MAX && INT_MIN < \at(n1, Pre) && \at(n1, Pre) < INT_MAX) ==> ((!(0 < \at(n0, Pre))) ==> ((k == 0)&&(i0 == 0)&&(n1 == \at(n1, Pre))&&(n0 == \at(n0, Pre))));
    loop invariant (INT_MIN < \at(n0, Pre) && \at(n0, Pre) < INT_MAX && INT_MIN < \at(n1, Pre) && \at(n1, Pre) < INT_MAX) ==> (n1 == \at(n1, Pre));
    loop invariant (INT_MIN < \at(n0, Pre) && \at(n0, Pre) < INT_MAX && INT_MIN < \at(n1, Pre) && \at(n1, Pre) < INT_MAX) ==> (n0 == \at(n0, Pre));
  */
  while( i0 < n0 ) {
    i0++;
    k++;
  }

  int i1 = 0;

  /*@ 
    loop invariant  (0 >= \at(n0, Pre) && INT_MIN < \at(n0, Pre) && \at(n0, Pre) < INT_MAX && INT_MIN < \at(n1, Pre) && \at(n1, Pre) < INT_MAX) ==> ((0 < \at(n1, Pre)) ==> (((i1 == 0)&&(k == 0)&&(i0 == 0)&&(n1 == \at(n1, Pre))&&(n0 == \at(n0, Pre))) || (k == i1))) ;
    loop invariant  (0 >= \at(n0, Pre) && INT_MIN < \at(n0, Pre) && \at(n0, Pre) < INT_MAX && INT_MIN < \at(n1, Pre) && \at(n1, Pre) < INT.MAX) ==> ((0 < \at(n1, Pre)) ==> (((i1 == 0)&&(k == 0)&&(i0 == 0)&&(n1 == \at(n1, Pre))&&(n0 == \at(n0, Pre))) || (i1 <= n1))) ;
    loop invariant (0 >= \at(n0, Pre) && INT_MIN < \at(n0, Pre) && \at(n0, Pre) < INT_MAX && INT_MIN < \at(n1, Pre) && \at(n1, Pre) < INT.MAX) ==> ((!(0 < \at(n1, Pre))) ==> ((i1 == 0)&&(k == 0)&&(i0 == 0)&&(n1 == \at(n1, Pre))&&(n0 == \at(n0, Pre))));
    loop invariant (0 >= \at(n0, Pre) && INT.MIN < \at(n0, Pre) && \at(n0, Pre) < INT.MAX && INT.MIN < \at(n1, Pre) && \at(n1, Pre) < INT.MAX) ==> (i0 == 0);
    loop invariant (0 >= \at(n0, Pre) && INT.MIN < \at(n0, Pre) && \at(n0, Pre) < INT.MAX && INT.MIN < \at(n1, Pre) && \at(n1, Pre) < INT.MAX) ==> (n1 == \at(n1, Pre));
    loop invariant (0 >= \at(n0, Pre) && INT.MIN < \at(n0, Pre) && \at(n0, Pre) < INT.MAX && INT.MIN < \at(n1, Pre) && \at(n1, Pre) < INT.MAX) ==> (n0 == \at(n0, Pre));
  */
  while( i1 < n1 ) {
    i1++;
    k++;
  }

  int j1 = 0;

  /*@ 
    loop invariant 0 <= j1 <= n0 + n1;
    loop invariant k == n0 + n1 - j1;
    loop invariant n0 == \at(n0, Pre);
    loop invariant n1 == \at(n1, Pre);
    loop invariant (INT_MIN < \at(n0, Pre) && \at(n0, Pre) < INT.MAX && INT.MIN < \at(n1, Pre) && \at(n1, Pre) < INT.MAX) ==> ((0 < \at(n0, Pre) + \at(n1, Pre)) ==> (((j1 == 0)) || (j1 <= \at(n0, Pre) + \at(n1, Pre) && k == (\at(n0, Pre) + \at(n1, Pre) - j1)))) ;
    loop invariant (INT.MIN < \at(n0, Pre) && \at(n0, Pre) < INT.MAX && INT.MIN < \at(n1, Pre) && \at(n1, Pre) < INT.MAX) ==> ((!(0 < \at(n0, Pre) + \at(n1, Pre))) ==> ((j1 == 0)));
  */
  while( j1 < n0 + n1 ) {
    /*@ assert k > 0; */
    j1++;
    k--;
  }
}
