
/*@
requires 0 < n;
*/
void foo(int n) {
    int k = 0;
    int i = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant  (0 < \at(n, Pre)) ==> ((0 < \at(n, Pre)) ==> (((i == 0)&&(k == 0)&&(n == \at(n, Pre))) || (k == i))) ;
      loop invariant  (0 < \at(n, Pre)) ==> ((0 < \at(n, Pre)) ==> (((i == 0)&&(k == 0)&&(n == \at(n, Pre))) || (i <= n))) ;
      loop invariant (0 < \at(n, Pre)) ==> ((!(0 < \at(n, Pre))) ==> ((i == 0)&&(k == 0)&&(n == \at(n, Pre))));
      loop invariant (0 < \at(n, Pre)) ==> (n == \at(n, Pre));
    */
    while (i < n) {
        i++;
        k++;
    }

    int j = n;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant (0 <= j <= n);
      loop invariant k == j;
      loop invariant n == \at(n, Pre);
    */
    while (j > 0) {
        j--;
        k--;
        /*@ assert k>=0; */
    }
}
