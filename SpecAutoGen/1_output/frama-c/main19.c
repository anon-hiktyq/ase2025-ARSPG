
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void reset_1st_if_2nd_is_true(int* a, int const* b)/*@
With a_v b_v
Require *(a) == a_v && *(b) == b_v
Ensure (b_v != 0 && (*a == 0) * (*b == b_v)) || (b_v == 0 && (*a == a_v) * (*b == b_v))
*/
{
    if(*b) *a = 0 ;
}
int main19()
/*@

Require emp

Ensure Results(__return)
*/{
    int a = 5 ;
    int x = 0 ;
    reset_1st_if_2nd_is_true(&a, &x);
    
    

    int const b = 1 ;
    reset_1st_if_2nd_is_true(&a, &b);
    
    
    return 0;
}