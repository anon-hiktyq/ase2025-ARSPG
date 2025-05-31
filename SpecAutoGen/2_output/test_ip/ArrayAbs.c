
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __TripleFabsMax
{


 int fabs[3];
 int tmax;
 int* ret;



} TripleFabsMax;

void ArrayAbs(int arr[3])
/*@
With arr_l
Require store_int_array(arr, 3, arr_l)
Ensure emp
*/{

    int i=0;
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for(; i < 3 ; i++ ){
        if( arr[i]<0 ){
            arr[i] = -arr[i];
        }
    }

   

}