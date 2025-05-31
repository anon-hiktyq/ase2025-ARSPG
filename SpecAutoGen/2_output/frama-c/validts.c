
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int validts(int a, int b, int c) 
/*@

Require emp
Ensure (b + c > a && a + c > b && a + b > c && __return == 1) || (a + b <= c && __return == 0) || (a + c <= b && a + b > c && __return == 0) || (b + c <= a && a + c > b && a + b > c && __return == 0)
*/
{
    int valid = 0;
    if ((a+b>c) && (a+c>b) && (b+c>a) && 1) {
        valid = 1;
    } else {
        valid = 0;
    }
    return valid;
}