
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int add14(int *p, int *q) /*@
With p_v q_v
Require *(p) == p_v && *(q) == q_v
Ensure (__return == p_v + q_v && (*p == p_v) * (*q == q_v))
*/
{
    return *p + *q;
}
int main14() 
/*@

Require emp

Ensure Results(__return)
*/{
    int a = 24;
    int b = 32;
    int x;

    x = add14(&a, &b) ;
    
    

    x = add14(&a, &a) ;
    
    
    return 0;
}