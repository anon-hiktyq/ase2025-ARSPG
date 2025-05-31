
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void main6()
/*@

Require emp

Ensure emp
*/{
    int i=0;

    while (i<30){
        ++i;
    }
    /*@ assert i==30; */
}