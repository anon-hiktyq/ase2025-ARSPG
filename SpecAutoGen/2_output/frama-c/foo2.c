
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int add(int x, int y) /*@

Require emp
Ensure (__return == x + y)
*/
{
    return x+y;
}
void foo2() 
/*@

Require emp
Ensure (exists retval_64, retval_64 == 997 + 997 && retval_57 == 1 + 43)
*/
{
    int a = add(1, 43);
    
    int b = add(997, 997);
}