
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int mul10(int a, int b) /*@

Require emp
Ensure Results(__return)
*/
{
    int x = a, y = b, prod = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((!(a@pre >= 0)) => ((prod == 0)&&(y == b@pre)&&(x == a@pre)&&(b == b@pre)&&(a == a@pre))) &&
(y == b@pre) &&
(b == b@pre) &&
(a == a@pre)
    */
    
    while(x >= 0) {
        prod = prod + y;
        x--;
    }
    return prod;
}
int main10() 
/*@

Require emp

Ensure Results(__return)
*/{
    int pdt = mul10(2, 5);
    
}