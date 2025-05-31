
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int func8(int c) /*@

Require emp
Ensure (exists x_59, x_59 <= 0 && (c > 0 => x_59 + __return == c) && (c > 0 => __return >= 0 && x_59 >= 0) && (!(c > 0) => __return == 0 && x_59 == c && c == c))
*/
{
    int x = c;
    int y = 0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((c@pre > 0) => (x + y == c@pre)) &&
((c@pre > 0) => (y >= 0 && x >= 0)) &&
((!(c@pre > 0)) => ((y == 0) && (x == c@pre) && (c == c@pre))) &&
(c == c@pre)
    */
    
    while(x > 0) {
        x = x - 1;
        y = y + 1;
    }
    return y;
}
void main8() 
/*@

Require emp
Ensure (exists retval_76 x_59_75, x_59_75 <= 0 && (5 > 0 => x_59_75 + retval_76 == 5) && (5 > 0 => retval_76 >= 0 && x_59_75 >= 0) && (!(5 > 0) => retval_76 == 0 && x_59_75 == 5 && 5 == 5))
*/
{
    int t = func8(5);
    
}