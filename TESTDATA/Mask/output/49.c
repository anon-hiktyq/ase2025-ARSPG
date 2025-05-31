
#include <stdbool.h>
int unknown();

/*@ requires n > 0; */
void foo(int n) {

    int c = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant ((c == 0)&&(n == \at(n, Pre))) || (c >= 1 && c <= n);
      loop invariant n == \at(n, Pre);
    */
    while (unknown()) {
        if (unknown()) {
            if (c != n) {
                c = c + 1;
            }
        } else {
            if (c == n) {
                c = 1;
            }
        }
    }
      /*@ assert (n <= -1) ==> (c != n ); */
}
