
int arraymax(int *a, int n) {
    int i = 1;
    int max = a[0];
  
    /*@
      loop invariant \forall integer j; 0 <= j < \at(n, Pre) ==> a[j] == \at(a, Pre)[j];
      loop invariant  (\at(n, Pre) > 0 && \at(n, Pre) < 100) ==> ((1 < \at(n, Pre)) ==> (1 <= i <= n)) ;
      loop invariant  (\at(n, Pre) > 0 && \at(n, Pre) < 100) ==> ((1 < \at(n, Pre)) ==> (((max == a[0])&&(i == 1)&&(n == \at(n, Pre))&&(a == \at(a, Pre))) || (\forall integer k; 0 <= k < i ==> max >= a[k]))) ;
      loop invariant (\at(n, Pre) > 0 && \at(n, Pre) < 100) ==> (n == \at(n, Pre));
      loop invariant (\at(n, Pre) > 0 && \at(n, Pre) < 100) ==> (a == \at(a, Pre));
    */
    while (i < n) {
      if (max < a[i])
        max = a[i];
      i = i + 1;
    }
            
    return max;
}
