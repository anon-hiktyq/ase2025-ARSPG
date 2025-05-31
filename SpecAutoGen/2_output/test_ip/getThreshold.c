
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

int getThreshold(int n)
/*@

Require emp
Ensure (exists i_64, i_64 > n && (0 <= n => 0 <= i_64 && i_64 <= n + 1) && (0 <= n => __return == i_64 * (i_64 - 1) / 2))
*/
{
    int i=0;
    int sum =0;
            
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 <= n@pre) => (0 <= i && i <= n+1) ) &&
((0 <= n@pre) => (sum == (i*(i-1))/2) ) &&
(n == n@pre)
    */
    
    while(i <= n){
        sum += i;
        i++;
    }       
    return sum;
}