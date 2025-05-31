
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void order_3(int *a, int *b, int *c) 
/*@
With a_v b_v c_v
Require *(a) == a_v && *(b) == b_v && *(c) == c_v
Ensure (b_v > c_v && a_v <= c_v && a_v <= b_v && (*a == a_v) * (*b == c_v) * (*c == b_v)) || (b_v > a_v && a_v > c_v && a_v <= b_v && (*a == c_v) * (*b == a_v) * (*c == b_v)) || (b_v <= a_v && a_v > c_v && a_v <= b_v && (*a == c_v) * (*b == b_v) * (*c == a_v)) || (a_v <= a_v && a_v > c_v && a_v > b_v && (*a == c_v) * (*b == a_v) * (*c == a_v)) || (a_v <= c_v && a_v <= c_v && a_v > b_v && (*a == a_v) * (*b == a_v) * (*c == c_v)) || (b_v <= c_v && a_v <= c_v && a_v <= b_v && (*a == a_v) * (*b == b_v) * (*c == c_v))
*/
{
    if (*a > *b) {
        int temp = *a;
        *b = *a;
        *a = temp;
    }
    if (*a > *c) {    
        int temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c) {
        int temp = *b;
        *b = *c;
        *c = temp;
    }
}