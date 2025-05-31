
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int diff (int x, int y) /*@

Require emp
Ensure (__return == x - y)
*/
{
    return x-y;
}
void main9() 
/*@

Require emp
Ensure (exists retval_57, retval_57 == 10 - 5)
*/
{
    int t = diff(10, 5);
    
}