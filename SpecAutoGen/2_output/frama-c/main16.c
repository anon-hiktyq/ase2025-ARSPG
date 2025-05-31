
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int incr_a_by_b(int* a, int * b)/*@
With a_v b_v
Require *(a) == a_v && *(b) == b_v
Ensure (__return == a_v + b_v && (*a == a_v + b_v) * (*b == b_v))
*/
{
    *a += *b;
    return *a;
}
void main16() 
/*@

Require emp
Ensure (exists retval_70 a_v_69, retval_70 == 10 + 20 && a_v_69 == 10 + 20)
*/
{
    int a = 10;
    int b = 20;
    incr_a_by_b(&a, &b);
    
    
}