
/*@ requires n >= 1;
    ensures (sn != n) ==> (sn == 0);
*/
void foo(int n) {
    int i = 1;
    int sn = 0;
    
    /*@ loop invariant 0 <= sn <= i - 1;
        loop invariant 1 <= i <= n + 1;
        loop invariant (sn != n) ==> (sn == 0);
        loop variant n - i;
    */
    while (i <= n) {
        i = (i + 1);
        sn = (sn + 1);
    }
    
    /*@ assert (sn != n) ==> (sn == 0); */
}
