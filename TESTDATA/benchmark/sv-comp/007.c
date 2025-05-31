
#include "assert.h"

/*@
requires 0 < n;
*/
void foo(int n) {
    int k = 0;
    int i = 0;


    while (i < n) {
        i++;
        k++;
    }
    int j = n;


    while (j > 0) {
        j--;
        k--;
        /*@ assert k > 0; */
    }


}
