
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int tt(int n)

/*@

Require emp
Ensure Results(__return)
*/{

    int i=0;
    int sum =0;

    if( n< 0 || n> 3){
        return 0;
    }
    

 while(i <= n){
        sum += i;
        i++;
    }
    return sum;
   
}