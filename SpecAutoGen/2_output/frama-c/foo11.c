
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int max ( int x, int y ) /*@

Require emp
Ensure (x < y && __return == y) || (x >= y && __return == x)
*/
{
    if ( x >=y ) 
        return x ;
    return y ;
}
void foo11()

/*@

Require emp
Ensure (exists retval_66, -43 < 34 && retval_66 == 34 && 34 < 45 && retval_58 == 45)
*/
{
    int s = max(34,45);
    
    int t = max(-43,34);
    
}