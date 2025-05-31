
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int array_1(int a[5]) /*@
With a_l
Require store_int_array(a, 5, a_l)
Ensure Results(__return)
*/
{
    int a = a[1]
    return a[1];
    
}
