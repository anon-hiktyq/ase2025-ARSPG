
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

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= i && i <= 30 )
    */
    
    while (i < 30) {
        ++i;
    }
    /*@ assert i==30; */
}