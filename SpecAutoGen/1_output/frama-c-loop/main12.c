
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int array_find(int* arr, int n, int x) /*@
With arr_l
Require store_int_array(arr, n, arr_l) && n > 0 && n < 100
Ensure Results(__return)
*/
{
    int i = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  arr_l ,    
    store_int_array(arr, n, arr_l) && n > 0 && n < 100 &&
    (forall (j:Z), 0 <= j && j < i => arr_l[j] != x) &&
((0 < n@pre) => (0 <= i && i <= n)) &&
((!(0 < n@pre)) => ((i == 0)&&(x == x@pre)&&(n == n@pre)&&(arr == arr@pre))) &&
(x == x@pre) &&
(n == n@pre) &&
(arr == arr@pre)
    */
    
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}
void main12() 
/*@

Require emp

Ensure emp
*/{
    int arr[5] = {1, 2, 3, 4, 5};
    int index = array_find(arr, 5, 3);
    
}