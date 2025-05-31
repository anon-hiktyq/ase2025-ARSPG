
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void array_swap(int* arr, int n, int n1, int n2) /*@
With arr_l
Require store_int_array(arr, n, arr_l) && n > 0 && n < 100
Ensure emp
*/
{
    int temp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = temp;
}
void main27() 
/*@

Require emp

Ensure emp
*/{
    int arr[5] = {1, 2, 3, 4, 5};
    array_swap(arr, 5, 0, 4);
    //@ assert arr[0] == 5;
    //@ assert arr[1] == 2;
    //@ assert arr[2] == 3;
    //@ assert arr[3] == 4;
    //@ assert arr[4] == 1;
}