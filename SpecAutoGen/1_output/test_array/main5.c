
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void arrayAbs(int *a, int n) /*@
With a_l
Require store_int_array(a, n, a_l) && n > 0 && n < 100
Ensure emp
*/
{
    int i = 0;
   
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l ,    
    store_int_array(a, n, a_l) && n > 0 && n < 100 &&
    (a == a@pre)
    */
    
    while (i < n) {
        if (a[i] < 0) {
            a[i] = -a[i];
        }
        i++;
    }
    
    

}
void main5() 
/*@

Require emp

Ensure emp
*/{
    int arr[5] = {1, -2, 3,- 4, 5};
    arrayAbs(arr, 5);
    //assert arr[1] == 2;
    //assert arr[3] == 4;
}