
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void arrayDouble(int *a, unsigned int n) /*@
With a_l
Require store_int_array(a, n, a_l) && n > 0 && n < 100
Ensure emp
*/
{
    int p = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l ,    
    store_int_array(a, n, a_l) && n > 0 && n < 100 &&
    ((0 < n@pre) => (0 <= p && p <= n@pre)) &&
((!(0 < n@pre)) => ((p == 0)&&(n == n@pre)&&(a == a@pre))) &&
(n == n@pre) &&
(a == a@pre)
    */
    
    while (p < n) {
        a[p] = a[p] * 2;
        p = p + 1;
    } 
}
int main19() 
/*@

Require emp

Ensure Results(__return)
*/{
    int arr[] = {0,1,2,3,4,5};
    arrayDouble(arr, 6);
    
    
    
    
    
    
}