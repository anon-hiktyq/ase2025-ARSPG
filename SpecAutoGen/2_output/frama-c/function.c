
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int function(int x, int y) 
/*@

Require emp
Ensure (__return == x@pre - 5 + (y@pre + 10))
*/
{
    int res ;
    y += 10 ;
    x -= 5 ;
    res = x + y ;
    
    return res ;
}