
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int foo1(int a)/*@

Require emp
Ensure (__return == a)
*/
{

    return a;

}
int main1()
/*@

Require emp

Ensure Results(__return)
*/{

   return foo1(5);

}