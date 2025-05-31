
#include <limits.h>

int unknown1();

/*@
requires l > 0;
requires l < INT_MAX;
requires n < INT_MAX;
*/
void foo(int n, int l) {
  int k = 1;

  /*@
    loop invariant (1 < \at(n, Pre)) ==> (l >= \at(l, Pre));
    loop invariant (1 < \at(n, Pre)) ==> (1 <= k <= n); 
    loop invariant (!(1 < \at(n, Pre))) ==> ((k == 1)&&(l == \at(l, Pre))&&(n == \at(n, Pre)));
    loop invariant n == \at(n, Pre);
  */
  for (; k < n; k++){
    int i = l;
   
    /*@
      loop invariant i >= l >= \at(l, Pre) && k < n;
    */
    for (; k < n; i++){
      /*@ assert 1 <= i;*/
    }
                
    if(unknown1()) {
      l = l + 1;
    }
  }
}
