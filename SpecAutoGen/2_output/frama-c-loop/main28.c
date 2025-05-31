
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int fun28(int x, int y , int *r) /*@
With r_v
Require *(r) == r_v
Ensure Results(__return)
*/
{
    *r = x;
    int d = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((*r@pre >= y@pre) => ((*r % y@pre == *r@pre % y@pre) && (d >= 0))) &&
((*r@pre >= y@pre) => (0 <= d)) &&
(y == y@pre) &&
(x == x@pre)
    */
    
    while (*r >= y) {
        *r = *r - y;
        d = d + 1;
    }
    return d;
}
int main28() 
/*@

Require emp

Ensure Results(__return)
*/{
    int a = 3;
    int num = fun28(1, 2, &a);
    //@ assert a == 1;
    //@ assert num == 0;
    return 0;
}