#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

int array_update(int *a, int n)
/*@ With l
    Require 0 < n && n < INT_MAX && store_int_array(a, n, l)
    Ensure exists l1,
            store_int_array(a, n, l1)
*/
{
    int i;
    /*@ Inv
        exists l1,
        0 <= i && i <= n@pre && store_int_array(a@pre, n@pre, l1) &&
        (forall (j : Z), (0 <= j && j < i) => (l1[j] == l[j] + 1)) 
    */
    for (i = 0; i < n; ++i) {
        a[i] = a[i] + 1;
    }
    return 0;
}