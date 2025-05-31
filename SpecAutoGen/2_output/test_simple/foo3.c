
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int foo3(int a, int b) 
/*@

Require emp
Ensure (a@pre > 0 && __return == a@pre + 1 + b) || (a <= 0 && __return == a + (b@pre + 1))
*/
{
    
    if(a> 0) { 
     a = a + 1;
    }else{
     b = b + 1;
    }
    
    return a+ b;
 }