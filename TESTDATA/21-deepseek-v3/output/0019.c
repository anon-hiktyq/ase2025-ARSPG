
#include <limits.h>

/*@
requires n <= INT_MAX;
*/
int foo(int n) {
  int i,k;
  k = n;
  i = 0;

 
  
                /*@
          loop invariant (!(0 < \at(n, Pre))) ==> ((k == \at(n, Pre))&&(i == 0)&&(n == \at(n, Pre)));
          loop invariant n == \at(n, Pre);
                */
                while( i < n ) {
    k--;
    i = i + 2;
  }
                

  int j = 0;

  
  
                
                /*@
          loop invariant (!(0 < \at(n, Pre)/2)) ==> ((j == 0)&&(n == \at(n, Pre)));
          loop invariant n == \at(n, Pre);
                */
                while( j < n/2 ) {
    /*@ assert k > 0; */
    k--;
    j++;
  }
                
  return 0;
}
