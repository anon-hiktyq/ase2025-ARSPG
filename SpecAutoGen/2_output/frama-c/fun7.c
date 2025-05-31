
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int fun7(int x, int y , int *r) 
/*@
With r_v
Require *(r) == r_v
Ensure Results(__return)
*/{
    *r = x;
    int d = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (*r >= y) {
        *r = *r - y;
        d = d + 1;
    }
    return d;
}