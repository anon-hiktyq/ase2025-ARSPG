
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int check(int *a, int *b, int n) 
/*@
With a_l b_l
Require store_int_array(a, b, a_l) && b > 0 && b < 100 && store_int_array(b, n, b_l) && n > 0 && n < 100
Ensure Results(__return)
*/{
    
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}