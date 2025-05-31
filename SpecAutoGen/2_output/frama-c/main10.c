
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void swap(int* a, int* b)/*@
With a_v b_v
Require *(a) == a_v && *(b) == b_v
Ensure ((*a == b_v) * (*b == a_v))
*/
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main10()
/*@

Require emp
Ensure (__return == 0)
*/
{
    int a = 42;
    int b = 37;

    swap(&a, &b);

    

    return 0;
}