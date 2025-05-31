
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int test(int x) /*@

Require emp
Ensure Results(__return)
*/
{
    int a = x;
    int y = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((x@pre != 0) => (a + y == x@pre) ) &&
((x@pre != 0) => (y >= 0) ) &&
((!(x@pre != 0)) => ((y == 0)&&(a == x@pre)&&(x == x@pre))) &&
(x == x@pre)
    */
    
    while(a != 0) {
        y = y + 1;
        a = a - 1;
    }
    return y;
}
int main5() 
/*@

Require emp

Ensure Results(__return)
*/{
    int num = test(3);
    
    return 0;
}