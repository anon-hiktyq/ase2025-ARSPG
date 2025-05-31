
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __TripleFabsMax
{


 int fx1;
 int fy2;
 int fz3;

 int *threshold;
 int tmax;
 int* ret;

} TripleFabsMax;

void getthreshold(int *threshold)
/*@
With threshold_v threshold_a
Require *(threshold) == threshold_v && (threshold) == threshold_a
Ensure emp
*/{
    
    int i =0;
   
    while(i<3){   
        i++;    
        *threshold = *threshold + i;  
    }

}