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
          loop invariant (0 < \at(n, Pre)) ==> (((k == 0)&&(i == 0)&&(c3 == 10000)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(n == \at(n, Pre))) || ((i <= n) && (k == (v == 0 ? c1 * i : (v == 1 ? c2 * i : c3 * i)))));
          loop invariant (0 < \at(n, Pre)) ==> (((k == 0)&&(i == 0)&&(c3 == 10000)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(n == \at(n, Pre))) || ((i <= n) && (k == (v == 0 ? c1 * i : (v == 1 ? c2 * i : c3 * i)))));
          loop invariant (!(0 < \at(n, Pre)) ==> ((k == 0)&&(i == 0)&&(c3 == 10000)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(n == \at(n, Pre))));
          loop invariant c3 == 10000;
          loop invariant c2 == 2000;
          loop invariant c1 == 4000;
          loop invariant v == \at(v, Pre);
          loop invariant n == \at(n, Pre);
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
          loop invariant (0 < \at(n, Pre)) ==> (((j == 0)&&(k == 0)&&(i == 0)&&(c3 == 10000)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(n == \at(n, Pre))) || ((k == (v == 0 ? c1 * n : (v == 1 ? c2 * n : c3 * n)) - j) && (j <= n)));
          loop invariant (0 < \at(n, Pre)) ==> (((j == 0)&&(k == 0)&&(i == 0)&&(c3 == 10000)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(n == \at(n, Pre))) || ((j <= n) && (k == (v == 0 ? c1 * n : (v == 1 ? c2 * n : c3 * n)) - j)));
          loop invariant (!(0 < \at(n, Pre))) ==> ((j == 0)&&(k == 0)&&(i == 0)&&(c3 == 10000)&&(c2 == 2000)&&(c1 == 4000)&&(v == \at(v, Pre))&&(n == \at(n, Pre)));
          loop invariant i == n;
          loop invariant c3 == 10000;
          loop invariant c2 == 2000;
          loop invariant c1 == 4000;
          loop invariant v == \at(v, Pre);
          loop invariant n == \at(n, Pre);
                */
                while (j < n) {
    /*@ assert k > 0; */
    j++;
    k--;
  }
                

  return 0;
}