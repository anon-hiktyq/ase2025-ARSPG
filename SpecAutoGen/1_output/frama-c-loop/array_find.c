
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    

int array_find(int* arr, int n, int x) 
/*@
With arr_l
Require store_int_array(arr, n, arr_l) && n > 0 && n < 100
Ensure Results(__return)
*/{
    int i = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}