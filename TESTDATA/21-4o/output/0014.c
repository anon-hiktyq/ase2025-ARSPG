
/*@
requires 0 <= n;
requires n < 1000;
*/
void foo(int n) {

    int i=0;
    int sn=0;

                /*@
          loop invariant  0 <= i <= n + 1;
          loop invariant  sn == 2 * (i - 1);
          loop invariant  n == \at(n, Pre);
                */
                for (i = 1; i <= n; i++) {
        sn = sn + (2);
    }
    
    /*@ assert sn == n * (2) || sn == 0; */
}
