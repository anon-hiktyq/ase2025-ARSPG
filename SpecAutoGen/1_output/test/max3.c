
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void max3 (int * a, int * b, int * c)
/*@
With a_v a_a b_v b_a c_v c_a
Require *(a) == a_v && (a) == a_a && *(b) == b_v && (b) == b_a && *(c) == c_v && (c) == c_a
Ensure emp
*/{

    int max = *a;
    if (*b > max) {
        max = *b;
    }
    if (*c > max) {
        max = *c;
    }
    *c = max; 


}