
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int fun(int x, int y) 
/*@

Require emp
Ensure Results(__return)
*/{
    int r = x;
    int d = 0;

    while (r >= y) {
       
        // Beginning
        r = r - y;
        d = d + 1;
        // ENd
        
    }
    return d;
}