
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int sum7(char n) 
/*@

Require emp
Ensure Results(__return)
*/{
    int s = 0;
    char k = 0;

    while(k <= n) {    
        s = s + (int)k;
        k = k + 1;
    }
    return (int)s;
}