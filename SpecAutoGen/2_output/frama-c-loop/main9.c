
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int factorial9(int n) /*@

Require emp
Ensure (1 > n && __return == 1)
*/
{

  int i = 1;
  int f = 1;

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 while (i <= n)  {
    f = f * i;
    i = i + 1;
  }
  return f;
}
void main9() 
/*@

Require emp
Ensure (1 > n && __return == 1)
*/
{
  int t = factorial9(5);
  
}