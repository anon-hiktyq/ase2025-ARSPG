
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int max_ptr(int *a, int *b)
/*@
With a_v b_v
Require *(a) == a_v && *(b) == b_v
Ensure (a_v < b_v && __return == b_v && (*a == a_v) * (*b == b_v)) || (a_v >= b_v && __return == a_v && (*a == a_v) * (*b == b_v))
*/
{
    return (*a < *b) ? *b : *a ;
}