
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int add2(int *a, int *b, int *r) 
/*@
With a_v b_v r_v
Require *(a) == a_v && *(b) == b_v && *(r) == r_v
Ensure (b_v != r_v && a_v != r_v && a_v != b_v && __return == a_v + b_v + r_v && (*a == a_v) * (*b == b_v) * (*r == r_v)) || (b_v == r_v && a_v != r_v && a_v != b_v && __return == a_v && (*a == a_v) * (*b == b_v) * (*r == r_v)) || (a_v == r_v && a_v != b_v && __return == b_v && (*a == a_v) * (*b == b_v) * (*r == r_v)) || (a_v == b_v && __return == r_v && (*a == a_v) * (*b == b_v) * (*r == r_v))
*/
{
    if (*a == *b) return *r;
    else if (*a == *r) return *b;
    else if (*b == *r) return *a;
    else return *a + *b + *r;
}