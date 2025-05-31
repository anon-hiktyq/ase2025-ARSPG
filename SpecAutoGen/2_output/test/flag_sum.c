
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void flag_sum(int flag,int * sum)
/*@
With sum_v
Require *(sum) == sum_v
Ensure emp
*/{

    int i = 0;

    *sum = flag;
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i < n) {
        *sum += i;
        i++;
    }
    

    


}