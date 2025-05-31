
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
Ensure (exists i_66, i_66 > n && 0 <= i_66 && i_66 <= n + 1 && __return == i_66 * (i_66 - 1) / 2 && (!(i_66 <= n) => __return == n * (n + 1) / 2) && n@pre >= 0 && n@pre <= 5) || (n > 5 && __return == 0) || (n < 0 && n <= 5 && __return == 0)
*/
{

    int i=0;
    int sum =0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (0 <= i && i <= n+1) &&
(sum == (i*(i-1))/2) &&
((!(i <= n)) => (sum == (n*(n+1))/2))
    */
    
    while(i <= n){
        sum += i;
        i++;
    }
            
    return sum;
   
}