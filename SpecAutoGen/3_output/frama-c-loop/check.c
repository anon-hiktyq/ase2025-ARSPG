
int check(int *a, int *b, int n) {

    /*@
      loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
      loop invariant (!(i < \at(n, Pre))) ==> ((n == \at(n, Pre))&&(b == \at(b, Pre))&&(a == \at(a, Pre)));
      loop invariant n == \at(n, Pre);
      loop invariant b == \at(b, Pre);
      loop invariant a == \at(a, Pre);
    */
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}
