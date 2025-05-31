
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void arrayDouble(int *a, unsigned int n) 
/*@
With a_l
Require store_int_array(a, n, a_l) && n > 0 && n < 100
Ensure emp
*/{
    int p = 0;

    while (p < n) {
        a[p] = a[p] * 2;
        p = p + 1;
    } 
}