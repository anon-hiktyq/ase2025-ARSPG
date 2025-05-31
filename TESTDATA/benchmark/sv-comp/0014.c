
/*@
requires 0 <= n;
requires n < 1000;
*/
void foo(int n) {

    int i=0;
    int sn=0;
    
   
    for (i = 1; i <= n; i++) {
        sn = sn + (2);
    }
    
    /*@ assert sn == n * (2) || sn == 0; */
}
