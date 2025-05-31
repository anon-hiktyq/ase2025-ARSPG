
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void increment_array_by(int* arr, int n, int c) 
/*@
With arr_l
Require store_int_array(arr, n, arr_l) && n > 0 && n < 100
Ensure emp
*/{
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l ,    
    store_int_array(arr, n, arr_l) && n > 0 && n < 100 &&
    ((!(i < n@pre)) => ((c == c@pre)&&(n == n@pre)&&(arr == arr@pre))) &&
(c == c@pre) &&
(n == n@pre) &&
(arr == arr@pre)
    */
    
            for (int  i = 0; i < n; i++) {
        arr[i] = arr[i] + c;
    }
}