
#include <limits.h>

int unknown1();

/*@
requires n < INT_MAX;
*/
int foo(int k, int n) {
    int i,j;

    if( k == n) {
    }
    else {
        return 0;
    }

    /*@
    loop invariant 0 <= i <= n;
    loop invariant k == n || k == \at(k,Pre);
    */
    for (i = 0; i < n; i++) {
        /*@
        loop invariant 2*i <= j <= n;
        loop invariant k == n || k == \at(k,Pre);
        loop invariant unknown1() ==> k == \at(k,Pre);
        loop invariant !unknown1() ==> k == n;
        */
        for (j= 2 * i; j < n; j++) {
            if(unknown1()) {
                /*@
                loop invariant j <= k <= n;
                loop invariant k >= 2*i;
                */
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
