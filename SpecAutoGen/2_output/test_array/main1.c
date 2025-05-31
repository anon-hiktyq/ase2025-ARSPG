
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int arraymax(int *a, int n) /*@
With a_l
Require store_int_array(a, n, a_l) && n > 0 && n < 100
Ensure Results(__return)
*/
{
    int i = 1;
    int max = a[0];
  
   
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  a_l ,    
    store_int_array(a, n, a_l) && n > 0 && n < 100 &&
    (forall (k:Z), 0 <= k && k < n => a_l[k] == a_l[k]@pre) &&
((n@pre > 0 && n@pre < 100) => ((1 < n@pre) => (1 <= i && i <= n))) &&
((n@pre > 0 && n@pre < 100) => ((1 < n@pre) => (((max == a_l[0])&&(i == 1)&&(n == n@pre)&&(a == a@pre)) || (forall (j:Z), 0 <= j && j < i => max >= a_l[j])))) &&
((n@pre > 0 && n@pre < 100) => ((!(1 < n@pre)) => ((max == a_l[0])&&(i == 1)&&(n == n@pre)&&(a == a@pre)))) &&
((n@pre > 0 && n@pre < 100) => (n == n@pre)) &&
((n@pre > 0 && n@pre < 100) => (a == a@pre))
    */
    
    while (i < n) {
      if (max < a[i])
        max = a[i];
      i = i + 1;
    }
    return max;
  }
void main1() 
/*@

Require emp

Ensure emp
*/{
    int arr[5] = {1, 2, 3, 4, 5};
    int max = arraymax(arr, 5);
    
    
    
    
    
  }