
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int add13(int *a, int *b, int *r) /*@
With a_v b_v r_v
Require *(a) == a_v && *(b) == b_v && *(r) == r_v
Ensure (__return == a_v + b_v + r_v && (*a == a_v) * (*b == b_v) * (*r == r_v))
*/
{
    return *a + *b + *r;
}
int main13() 
/*@

Require emp

Ensure Results(__return)
*/{
    int a = 24;
    int b = 32;
    int r = 12;
    int x;

    x = add13(&a, &b, &r) ;
    
    

    x = add13(&a, &a, &a) ;
    
    
    return 0;
}