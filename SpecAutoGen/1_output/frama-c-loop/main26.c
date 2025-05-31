
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int func26(int num) /*@

Require emp
Ensure (exists i_59, num <= 0 && (num@pre > 0 => num >= 0) && (num@pre > 0 => __return >= 0) && (!(num@pre > 0) => __return == 0 && i_59 == 0 && num == num@pre))
*/
{
    int i = 0;
    int sum = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((num@pre>0) => (num >= 0)) &&
((num@pre>0) => (sum >= 0)) &&
((!(num@pre>0)) => ((sum == 0)&&(i == 0)&&(num == num@pre)))
    */
    
    while(num>0) {
        i = num % 10;
        sum += i;
        num /= 10;
    }
    return sum;
}
void main26() 
/*@

Require emp

Ensure emp
*/{
    int t = func26(123);
    
}