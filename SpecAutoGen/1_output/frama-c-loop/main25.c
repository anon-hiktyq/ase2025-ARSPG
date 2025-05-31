
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int areElementsEven(int *a, int n) /*@
With a_l
Require store_int_array(a, n, a_l) && n > 0 && n < 100
Ensure (exists a_l_62 p_61, p_61 >= n && n > 0 && n < 100 && (forall k_52, 0 <= k_52 && k_52 < p_61 => a_l_62[k_52] % 2 == 0) && (0 < n => p_61 >= 0 && p_61 <= n) && (!(0 < n) => p_61 == 0 && n == n && a == a) && n > 0 && n < 100 && __return == 1 && store_int_array(a, n, a_l_62)) || (a_l_62[p_61] % 2 != 0 && p_61 < n && n > 0 && n < 100 && (forall k_52, 0 <= k_52 && k_52 < p_61 => a_l_62[k_52] % 2 == 0) && (0 < n => p_61 >= 0 && p_61 <= n) && (!(0 < n) => p_61 == 0 && n == n && a == a) && n > 0 && n < 100 && __return == 0 && store_int_array(a, n, a_l_62))
*/
{
    int p = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l ,    
    store_int_array(a, n, a_l) && n > 0 && n < 100 &&
    (forall (k:Z), 0 <= k && k < p => a_l[k] % 2 == 0) &&
((0 < n@pre) => (p >= 0 && p <= n@pre)) &&
((!(0 < n@pre)) => ((p == 0) && (n == n@pre) && (a == a@pre))) &&
(n == n@pre) &&
(a == a@pre)
    */
    
    while (p < n) {
        if (a[p] % 2 != 0) {
            return 0;
        }
        p = p + 1;
    }
    return 1;
}
void main25() 
/*@

Require emp

Ensure emp
*/{
    int arr[] = {2,4,6,8,10};
    int res = areElementsEven(arr, 5);
    
}