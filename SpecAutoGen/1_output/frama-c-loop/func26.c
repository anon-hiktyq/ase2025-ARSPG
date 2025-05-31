
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int func26(int num) 
/*@

Require emp
Ensure Results(__return)
*/{
    int i = 0;
    int sum = 0;

    while(num>0) {
        i = num%10;
        sum += i;
        num /= 10;
    }
    return sum;
}