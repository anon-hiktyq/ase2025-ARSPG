
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int triangle(int a, int b, int c) /*@

Require emp
Ensure (c <= 0 && b > 0 && a > 0 && a + b + c == 180 && __return == 0) || (b <= 0 && a > 0 && a + b + c == 180 && __return == 0) || (a <= 0 && a + b + c == 180 && __return == 0) || (a + b + c != 180 && __return == 0) || (c > 0 && b > 0 && a > 0 && a + b + c == 180 && __return == 1)
*/
{
    if ((a+b+c == 180) && a > 0 && b > 0 && c > 0) {
        return 1;
    } else {
        return 0;
    }
}
void check_validity() 
/*@

Require emp
Ensure (exists retval_71, 90 + 145 + 145 != 180 && retval_71 == 0 && 45 > 0 && 45 > 0 && 90 > 0 && 90 + 45 + 45 == 180 && retval_61 == 1)
*/
{
    int res = triangle(90, 45, 45);
    
    res = triangle(90, 145, 145);
    
}