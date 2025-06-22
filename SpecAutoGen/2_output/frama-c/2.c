#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

int foo(int *a,int *b)
/*@
With a_v b_v
Require a == b && *a == a_v && *b == b_v
Ensure __return == 0
*/
{
  *a = *a  +1;
  *b = *b + 1;
  return *a + *b;
}


