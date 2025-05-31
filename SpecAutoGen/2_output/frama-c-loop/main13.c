
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int array_max_advanced(int* arr, int n) /*@
With arr_l
Require store_int_array(arr, n, arr_l) && n > 0 && n < 100
Ensure Results(__return)
*/
{
    int max = arr[0];
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l ,    
    store_int_array(arr, n, arr_l) && n > 0 && n < 100 &&
    ((forall (k:Z), 0 <= k && k < i => arr_l[k] <= max)) &&
((i < n) => ((n == n@pre) && (arr == arr@pre))) &&
((!(i < n)) => ((forall (k:Z), 0 <= k && k < n => arr_l[k] <= max) && (n == n@pre) && (arr == arr@pre))) &&
(n == n@pre) &&
(arr == arr@pre)
    */
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void main13() 
/*@

Require emp

Ensure emp
*/{
    int arr[5] = {1, 2, 3, 4, 5};
    int max = array_max_advanced(arr, 5);
    
    
    
    
    
}