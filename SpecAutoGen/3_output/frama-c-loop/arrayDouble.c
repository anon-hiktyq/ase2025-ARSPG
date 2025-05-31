
void arrayDouble(int *a, unsigned int n) {
    int p = 0;

    /*@
      loop invariant (0 < \at(n, Pre)) ==> (0 <= p <= \at(n, Pre));
      loop invariant (!(0 < \at(n, Pre))) ==> ((p == 0)&&(n == \at(n, Pre))&&(a == \at(a, Pre)));
      loop invariant n == \at(n, Pre);
      loop invariant a == \at(a, Pre);
    */
    while (p < n) {
        a[p] = a[p] * 2;
        p = p + 1;
    }
}
