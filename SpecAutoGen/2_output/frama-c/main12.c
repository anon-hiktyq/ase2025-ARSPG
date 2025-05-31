
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int simple(int p,int n,int r)
/*@

Require emp
Ensure (__return == p * n * r / 100)
*/
{
    int si;
    si = p*n*r/100;
    return si;
}
int main12()

/*@

Require emp
Ensure (exists retval_65, retval_65 == 10000 * 3 * 10 / 100 && __return == 0)
*/
{
    int s = simple(10000, 3,10);
    return 0;
}