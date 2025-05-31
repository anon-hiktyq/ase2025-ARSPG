
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int fun(int x, int y) 
/*@

Require emp
Ensure (exists r_64, r_64 < y && (x >= y => r_64 == x - __return * y) && (x >= y => __return >= 0) && (!(x >= y) => __return == 0 && r_64 == x && y == y && x == x))
*/
{
    int r = x;
    int d = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre >= y@pre) => (r == x@pre - d * y@pre) ) &&
((x@pre >= y@pre) => (d >= 0) ) &&
((!(x@pre >= y@pre)) => ((d == 0)&&(r == x@pre)&&(y == y@pre)&&(x == x@pre))) &&
(y == y@pre) &&
(x == x@pre)
    */
    
    while (r >= y) {
        // Beginning
        r = r - y;
        d = d + 1;
        // End
    }
    return d;
}