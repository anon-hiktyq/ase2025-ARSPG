
int areElementsEven(int *a, int n) {
    int p = 0;

    /*@
      loop invariant \forall integer k; 0 <= k < p ==> a[k] % 2 == 0;
      loop invariant (0 < \at(n, Pre)) ==> (p >= 0 && p <= \at(n, Pre));
      loop invariant (!(0 < \at(n, Pre))) ==> ((p == 0) && (n == \at(n, Pre)) && (a == \at(a, Pre)));
      loop invariant n == \at(n, Pre);
      loop invariant a == \at(a, Pre);
    */
    while (p < n) {
        if (a[p] % 2 != 0) {
            return 0;
        }
        p = p + 1;
    }

    return 1;
}
