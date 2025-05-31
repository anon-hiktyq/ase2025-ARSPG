
#include <limits.h>

int unknown1();

/*@
requires n < INT_MAX && k == n;
*/
void foo(int k, int n) {
    int i,j;

    i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant \forall integer x; 0 <= x < i ==> j >= 2*x;
        loop invariant k == \old(k);
        loop invariant n == \old(n);
    */
    for (i = 0; i < n; i++) {
        
        j = 2* i;
        /*@ loop invariant 2*i <= j <= n;
            loop invariant k == \old(k);
        */
        for (j= 2 * i; j < n; j++) {
            if(unknown1()) {
                /*@ loop invariant j <= k <= n;
                    loop invariant k >= 2*i;
                */
                for (k = j; k < n; k++) {
                    /*@ assert k >= 2*i; */
                }
            }
            else {
                /*@ assert k >= n && k <= n; */
            }
        }
    }
}
