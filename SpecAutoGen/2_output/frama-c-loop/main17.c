
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int fun17(int n) /*@

Require emp
Ensure Results(__return)
*/
{
    int i = 7;
    int x = 1;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((7 <= n@pre) => (x == ((i - 7) / 3) + 1) ) &&
((7 <= n@pre) => (i == 7 + 3 * (x - 1)) ) &&
((!(7 <= n@pre)) => ((x == 1)&&(i == 7)&&(n == n@pre))) &&
(n == n@pre)
    */
    
    while(i <= n) {
        x += 1;
        i += 3;
    }
    return x;
}
int main17() 
/*@

Require emp

Ensure Results(__return)
*/{
    int a = fun17(10);
    
}