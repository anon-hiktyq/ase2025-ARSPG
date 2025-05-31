
#include <limits.h>

/*@
requires INT_MIN < n && n < INT_MAX;
requires INT_MIN < m && m < INT_MAX;
requires INT_MIN < l && l < INT_MAX;
requires 3 * n <= m + l;
*/
void foo(int n, int m, int l) {
    int i, j, k;

    i = 0;
    for (i = 0; i < n; i++) {
        j = 2 * i;
        for (j = 2 * i; j < 3 * i; j++) {
            k = i;
            /* >>> LOOP INVARIANT TO FILL <<< */
            /*@ 
              loop invariant i <= k <= j;
              */
            for (k = i; k < j; k++) {
                /*@ assert k - i <= 2 * n; */
            }
        }
    }
}
