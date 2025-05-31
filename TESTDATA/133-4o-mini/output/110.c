
/*@ requires n >= 1;
*/
void foo(int n) {

    int i = 1;
    int sn = 0;
    
    /*@
      loop invariant (1 <= \at(n, Pre)) ==> (((sn == 0)&&(i == 1)&&(n == \at(n, Pre))) || (i >= 1 && i <= n + 1));
      loop invariant (1 <= \at(n, Pre)) ==> (((sn == 0)&&(i == 1)&&(n == \at(n, Pre))) || (sn == i - 1));
      loop invariant !(1 <= \at(n, Pre) ) ==> ((sn == 0)&&(i == 1)&&(n == \at(n, Pre)));
      loop invariant n == \at(n, Pre);
    */
    while (i <= n) {
        i  = (i + 1);
        sn  = (sn + 1);
    }
    
    /*@ assert (sn!= n) ==> (sn ==0); */
}
