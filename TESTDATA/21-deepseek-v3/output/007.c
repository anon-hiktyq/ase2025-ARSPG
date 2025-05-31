
#include "assert.h"

/*@
requires 0 < n;
*/
void foo(int n) {
    int k = 0;
    int i = 0;

    /*@
      loop invariant (0 < \at(n, Pre)) ==> (k == i);
      loop invariant (0 < \at(n, Pre)) ==> (0 <= i <= n);
      loop invariant (!(0 < \at(n, Pre))) ==> ((i == 0)&&(k == 0)&&(n == \at(n, Pre)));
      loop invariant n == \at(n, Pre);
    */
    while (i < n) {
        i++;
        k++;
    }

    int j = n;

    /*@
      loop invariant (\at(n, Pre) > 0) ==> (0 <= j <= \at(n, Pre) && k == j && (j > 0 ==> k > 0));
      loop invariant (!(\at(n, Pre) > 0)) ==> ((j == \at(n, Pre))&&(n == \at(n, Pre)));
      loop invariant n == \at(n, Pre);
    */
    while (j > 0) {
        j--;
        k--;
        /*@ assert k > 0; */
    }

    return;
}
