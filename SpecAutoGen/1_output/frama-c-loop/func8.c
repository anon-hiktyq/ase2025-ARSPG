
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int func8(int c) 
/*@

Require emp
Ensure Results(__return)
*/{
    int x = c;
    int y = 0;

    while(x > 0) {
        x = x - 1;
        y = y + 1;
    }
    return y;
}