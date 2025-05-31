
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int func11(int n) /*@

Require emp
Ensure Results(__return)
*/
{
    int sum = 0;
    int i = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 <= n@pre/2) => (sum == i * (i - 1))) &&
((0 <= n@pre/2) => (0 <= i && i <= n/2 + 1)) &&
((!(0 <= n@pre/2)) => ((i == 0)&&(sum == 0)&&(n == n@pre))) &&
(n == n@pre)
    */
    
    while(i <= n/2) {
        sum = sum + 2*(i);
        i++;
    }
    return sum;
}
void main11() 
/*@

Require emp

Ensure emp
*/{
    int t = func11(10);
    
}