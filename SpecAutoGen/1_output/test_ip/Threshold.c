
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __TripleAbsMax
{


 int fabs[3];
 int tmax;
 int* ret;



} TripleAbsMax;

int Threshold(int n)

/*@

Require emp
Ensure Results(__return)
*/{

    int i=0;
    int sum =0;

    if (n > 5 || n < 0){
        return 0;
    } 

    while(i <= n){
        sum += i;
        i++;
    }
            
    return sum;
   
}