
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int arrayInit(int *a,int n) 
/*@
With a_l
Require store_int_array(a, n, a_l) && n > 0 && n < 100
Ensure Results(__return)
*/{
    int j =0;
    int i = 0;
    
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l ,    
    store_int_array(a, n, a_l) && n > 0 && n < 100 &&
    (forall (k:Z), 0 <= k && k < i => a_l[k] == k) &&
((0 < n@pre) => (((i == 0)&&(j == 0)&&(n == n@pre)&&(a == a@pre)) || (j == 10))) &&
((0 < n@pre) => (0 <= i && i <= n)) &&
((!(0 < n@pre)) => ((i == 0)&&(j == 0)&&(n == n@pre)&&(a == a@pre))) &&
(n == n@pre) &&
(a == a@pre)
    */
    
    for (; i < n; ++i) {
        a[i] = i;
        j =10;
    }
    return 0;
}