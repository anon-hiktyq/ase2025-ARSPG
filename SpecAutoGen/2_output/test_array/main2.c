
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */



int arrayHead(int *a) /*@
With a_l
Require store_int_array(a,10, a_l)
Ensure (__return == a_l[0] && store_int_array(a, 10, a_l))
*/
{
    int i = 1;
    int max = a[0];
    return max;
  }
int main2() 
/*@
Require emp
Ensure emp
*/
{
    int arr[5] = {1, 2, 3, 4, 5};

    int head = arrayHead(arr);
    return head;
}