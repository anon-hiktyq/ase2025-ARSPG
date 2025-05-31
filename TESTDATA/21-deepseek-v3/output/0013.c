
#include <limits.h>


/*@
requires INT_MIN < n && n < INT_MAX;
requires INT_MIN < m && m < INT_MAX;
requires INT_MIN < l && l < INT_MAX;
requires 3*n <= m + l;
*/
void foo(int n, int m , int l) {
    int i, j, k;

    i = 0;
    
                /*@
          loop invariant 0 <= i <= n && 
                         0 <= k - i <= 2 * n;
                */
                for (; i < n; i++) {
       
        j = 2 * i;
        for (; j < 3 * i; j++) {
            k = i;
            
            for (; k < j; k++) {
                /*@ assert k - i <= 2 * n; */
            }
        }
    }
                
}
