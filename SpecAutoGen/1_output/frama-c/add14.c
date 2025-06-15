
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int add14(int *p, int *q) 
/*@
With p_v q_v
Require *(p) == p_v && *(q) == q_v
Ensure Results(__return)
*/{
    return *p + *q;
}