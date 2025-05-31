
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int add2(int *a, int *b, int *r) 
/*@
With a_v b_v r_v
Require *(a) == a_v && *(b) == b_v && *(r) == r_v
Ensure Results(__return)
*/{
    if (*a == *b) return *r;
    else if (*a == *r) return *b;
    else if (*b == *r) return *a;
    else return *a + *b + *r;
}