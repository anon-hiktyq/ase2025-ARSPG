
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int add1(int *a, int *b, int *r) 
/*@
With a_v b_v r_v
Require *(a) == a_v && *(b) == b_v && *(r) == r_v
Ensure Results(__return)
*/{
    return *a + *b + *r;
}