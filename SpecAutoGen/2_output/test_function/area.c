
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int area(int base, int height)
/*@

Require emp
Ensure (__return == base * height / 2)
*/
{
    int res = (base * height)/2;
    return res;
}