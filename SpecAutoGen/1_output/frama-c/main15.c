
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void div_rem(unsigned x, unsigned y, unsigned* q, unsigned* r) /*@
With q_v r_v
Require *(q) == q_v && *(r) == r_v
Ensure ((*q == x / y) * (*r == x % y))
*/
{
    *q = x / y;
    *r = x % y;
}
void main15() 
/*@

Require emp

Ensure emp
*/{
    unsigned q, r;
    div_rem(10, 3, &q, &r);
    
    
   
}