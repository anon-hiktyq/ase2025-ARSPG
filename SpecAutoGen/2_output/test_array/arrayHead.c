
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int arrayHead(int *a,int n) 
/*@
With a_l
Require store_int_array(a, n, a_l) && n > 0 && n < 100
Ensure (n > 0 && n < 100 && __return == a_l[0] && store_int_array(a, n, a_l))
*/
{
    int i = 1;
    int max = a[0];
    return max;
  }