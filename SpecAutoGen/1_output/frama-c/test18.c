
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void order_3(int *a, int *b, int *c) /*@
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
void test18()
/*@

Require emp

Ensure emp
*/{
    
    int a1 = 5, b1 = 3, c1 = 4 ;
    order_3(&a1, &b1, &c1) ;
    //@ assert a1 == 3 && b1 == 4 && c1 == 5;
    
    int a2 = 2, b2 = 2, c2 = 2 ;
    order_3(&a2, &b2, &c2) ;
    //@ assert a2 == 2 && b2 == 2 && c2 == 2 ;

    int a3 = 4, b3 = 3, c3 = 4 ;
    order_3(&a3, &b3, &c3) ;
    //@ assert a3 == 3 && b3 == 4 && c3 == 4 ;

    int a4 = 4, b4 = 5, c4 = 4 ;
    order_3(&a4, &b4, &c4) ;
    //@ assert a4 == 4 && b4 == 4 && c4 == 5 ;
}