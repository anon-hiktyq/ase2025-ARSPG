
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int binarysearch(int* a, int x, int n) 
/*@
With a_l
Require store_int_array(a, x, a_l) && x > 0 && x < 100
Ensure Results(__return)
*/{

    int low = -1;
    int high = n;
    int p;

    while (low+1 < high) {
        p = (low + high) / 2;
        if (a[p] == x) 
            return p;
        else 
            if (a[p] < x)
            low = p;
            else high = p;
    }
    return -1;
}