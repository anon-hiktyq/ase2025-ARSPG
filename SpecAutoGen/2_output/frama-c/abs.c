
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int abs(int val) 
/*@

Require emp
Ensure (val >= 0 && __return == val) || (val < 0 && __return == -val)
*/
{
    if(val < 0) return -val;
    return val;
}