
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int func3(int *a, int n, int x, int *sum) /*@
With a_l sum_v
Require store_int_array(a, n, a_l) && n > 0 && n < 100 && *(sum) == sum_v
Ensure Results(__return)
*/
{
    int p = 0;
    int count = 0;
    *sum = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l ,    
    store_int_array(a, n, a_l) && n > 0 && n < 100 &&
    (forall (k:Z), 0 <= k && k < p => (a_l[k] == x => *sum == count * x)) &&
(*sum == count * x) &&
(count >= 0 && count <= p) &&
(x == x@pre) &&
(n == n@pre) &&
(a == a@pre)
    */
    
    while (p < n) {
        if (a[p] == x) {
            count = count + 1;
            *sum = *sum + x;
        }
        p = p + 1;
    }
    Label_a:
    *sum += 0;
    
    return count;
}
void main3() 
/*@

Require emp

Ensure emp
*/{
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    int count = func3(arr, 5, 3, &sum);
    
}