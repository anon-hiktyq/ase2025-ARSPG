
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int abs(int val) /*@

Require emp
Ensure (val >= 0 && __return == val) || (val < 0 && __return == -val)
*/
{
    if(val < 0) return -val;
    return val;
}
void foo1(int a) 
/*@

Require emp
Ensure (exists retval_81, -997 < 0 && retval_81 == --997 && a >= 0 && retval_71 == a && 42 >= 0 && retval_64 == 42 && -42 < 0 && retval_56 == --42) || (exists retval_77, -997 < 0 && retval_77 == --997 && a < 0 && retval_70 == -a && 42 >= 0 && retval_64 == 42 && -42 < 0 && retval_56 == --42)
*/
{
    int b = abs(-42);
    
    int c = abs(42);
    
    int d = abs(a);
    int e = abs(-997);

}