
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

void array_swap(int* arr, int n, int n1, int n2) 
/*@
With arr_l
Require store_int_array(arr, n, arr_l) && n > 0 && n < 100
Ensure emp
*/{
    int temp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = temp;
}