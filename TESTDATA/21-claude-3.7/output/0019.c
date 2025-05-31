
#include <limits.h>


/*@
requires n <= INT_MAX;
*/
void foo(int n) {
  int i,k;
  k = n;
  i = 0;

  
                
                /*@
          loop invariant  (\at(n, Pre) <= INT_MAX) ==> ((0 < \at(n, Pre)) ==> (((k == \at(n, Pre))&&(i == 0)&&(n == \at(n, Pre))) || (0 <= i && i <= n+1 && (i % 2 == 0)))) ;
          loop invariant  (\at(n, Pre) <= INT_MAX) ==> ((0 < \at(n, Pre)) ==> (((k == \at(n, Pre))&&(i == 0)&&(n == \at(n, Pre))) || (k == n - i/2))) ;
          loop invariant (\at(n, Pre) <= INT_MAX) ==> ((!(0 < \at(n, Pre))) ==> ((k == \at(n, Pre))&&(i == 0)&&(n == \at(n, Pre))));
          loop invariant (\at(n, Pre) <= INT_MAX) ==> (n == \at(n, Pre));
                */
                while( i < n ) {
    k--;
    i = i + 2;
  }
                

  int j = 0;
 
  
                /*@
          loop invariant k == n - i/2 - j;
          loop invariant j < n/2 ==> k >= 0;
                */
                while( j < n/2 ) {
    /*@ assert k>0; */
    k--;
    j++;
  }
                

}
