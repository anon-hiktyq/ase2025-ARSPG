
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void arrayAbs(int a[3]) 
/*@
With a_l
Require store_int_array(a, 3, a_l)
Ensure emp
*/{
    int i = 0;
   
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i < 3) {
      if (a[i] < 0) {
        a[i] = -a[i];
      }
      i++;
    }
    
   

}