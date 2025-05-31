
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int arrayInit(int *a,int n) 
/*@
With a_l
Require store_int_array(a, n, a_l) && n > 0 && n < 100
Ensure Results(__return)
*/{
    int j =0;
    int i = 0;
    
    for (; i < n; ++i) {
        a[i] = i;
        j =10;

    }
    return 0;
}