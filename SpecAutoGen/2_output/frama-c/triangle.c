
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int triangle(int a, int b, int c) 
/*@

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