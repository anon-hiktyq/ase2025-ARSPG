
#include <limits.h>

int unknown1();

/*@
requires n < INT_MAX;
requires k == n;
*/
int foo(int k, int n) {
    int i,j;

    i = 0;

    for (; i < n; i++) {
        
        j = 2*i;
        
        for (; j < n; j++) {
            if(unknown1()) {
                
                for (k = j; k < n; k++) {
                    /*@ assert k >= 2*i;*/
                }
            }
            else {
                /*@ assert k>=n && k <= n;*/
            }
        }
    }
}
