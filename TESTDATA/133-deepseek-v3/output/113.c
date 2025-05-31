
/*@ requires n >= 1;
*/
void foo(int n,int v1,int v2,int v3) {

    int i = 1;
    int sn = 0;
    
    /*@
      loop invariant (1 <= \at(n, Pre)) ==> (((sn == 0)&&(i == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(n == \at(n, Pre))) || (sn == i - 1));
      loop invariant (1 <= \at(n, Pre)) ==> (((sn == 0)&&(i == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(n == \at(n, Pre))) || (sn == i - 1));
      loop invariant (!(1 <= \at(n, Pre))) ==> ((sn == 0)&&(i == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(n == \at(n, Pre)));
      loop invariant v3 == \at(v3, Pre);
      loop invariant v2 == \at(v2, Pre);
      loop invariant v1 == \at(v1, Pre);
      loop invariant n == \at(n, Pre);
      loop invariant 1 <= i <= n + 1;
      loop invariant sn == i - 1;
    */
    while (i <= n) {
        i  = (i + 1);
        sn  = (sn + 1);
    }
    
    /*@ assert (sn != 0) ==> (sn == n); */
}
