

int sumArray(int *a, int n) {
    int p = 0, sum = 0;

    /*@
      loop invariant \forall integer k; 0 <= k < p ==> \at(a, Pre)[k] == a[k] ;
      loop invariant (0 < \at(n, Pre)) ==> (0 <= p <= \at(n, Pre)) ;
      loop invariant (!(0 < \at(n, Pre))) ==> ((sum == 0)&&(p == 0)&&(n == \at(n, Pre))&&(a == \at(a, Pre)));
      loop invariant n == \at(n, Pre);
      loop invariant a == \at(a, Pre);
    */
    while (p < n) {
        sum = sum + a[p];
        p++;
    }

    return sum;
}

