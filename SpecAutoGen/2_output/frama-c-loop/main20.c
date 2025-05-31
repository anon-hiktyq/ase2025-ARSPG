
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int sumArray(int *a, int n) /*@
With a_l
Require store_int_array(a, n, a_l) && n > 0 && n < 100
Ensure Results(__return)
*/
{
    int p = 0, sum = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l ,    
    store_int_array(a, n, a_l) && n > 0 && n < 100 &&
    (forall (k:Z), 0 <= k && k < p => a@pre_l[k] == a_l[k] ) &&
((0 < n@pre) => (0 <= p && p <= n@pre) ) &&
((!(0 < n@pre)) => ((sum == 0)&&(p == 0)&&(n == n@pre)&&(a == a@pre))) &&
(n == n@pre) &&
(a == a@pre)
    */
    
    while (p < n) {
        sum = sum + a[p];
        p++;
    }
    return sum;
}
void main20() 
/*@

Require emp

Ensure emp
*/{
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = sumArray(arr, 5);
    
}