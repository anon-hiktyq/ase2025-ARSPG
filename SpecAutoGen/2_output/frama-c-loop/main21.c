
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int binarysearch(int* a, int x, int n) /*@
With a_l
Require store_int_array(a, x, a_l) && x > 0 && x < 100
Ensure Results(__return)
*/
{

    int low = -1;
    int high = n;
    int p;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l ,    
    store_int_array(a, x, a_l) && x > 0 && x < 100 &&
    (low >= -1 && high <= n) &&
((-1+1 < n@pre) => (((high == n@pre)&&(low == -1)&&(n == n@pre)&&(x == x@pre)&&(a == a@pre)) || (low >= -1))) &&
((-1+1 < n@pre) => (high <= n) ) &&
((!(-1+1 < n@pre)) => ((high == n@pre)&&(low == -1)&&(n == n@pre)&&(x == x@pre)&&(a == a@pre))) &&
(n == n@pre) &&
(x == x@pre) &&
(a == a@pre)
    */
    
            while (low+1 < high) {
        p = (low + high) / 2;
        if (a[p] == x) 
            return p;
        else 
            if (a[p] < x)
            low = p;
            else high = p;
    }
    return -1;
}
void main21() 
/*@

Require emp

Ensure emp
*/{
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = binarysearch(arr, 3, 5);
    
}