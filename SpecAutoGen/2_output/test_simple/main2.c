
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int foo2(int a)/*@

Require emp
Ensure (__return >= 10 && (a@pre < 10 => __return == a@pre || a@pre < __return && __return <= 10) && (!(a@pre < 10) => __return == a@pre))
*/
{

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((a@pre<10) => (((a == a@pre)) || (a@pre < a && a <= 10))) &&
((!(a@pre<10)) => ((a == a@pre)))
    */
    
    while (a<10 ){
        a++;
    }
    return a;

}
int main2()
/*@

Require emp
Ensure (__return >= 10 && (5 < 10 => __return == 5 || 5 < __return && __return <= 10) && (!(5 < 10) => __return == 5))
*/
{

   return foo2(5);

}