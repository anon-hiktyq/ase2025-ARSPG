
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int mul10(int a, int b) 
/*@

Require emp
Ensure Results(__return)
*/{
    int x = a, y = b, prod = 0;

    while(x >= 0) {
        prod = prod + y;
        x--;
    }
    return prod;
}