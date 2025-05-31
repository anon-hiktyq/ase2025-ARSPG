
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int f(int * b)
/*@
With b_v
Require *(b) == b_v
Ensure (__return == b_v + 1 && *b == b_v + 1)
*/
{
    
    *b = *b + 1;
    return *b;
  
}