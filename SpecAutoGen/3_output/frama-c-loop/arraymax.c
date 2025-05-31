
int arraymax(int* a, int n) {
  int i = 1;
  int max = a[0];

  
            
            /*@
          loop invariant \forall integer j; 0 <= j < n ==> a[j] == \at(a[j], Pre);
          loop invariant (1 < \at(n, Pre)) ==> (1 <= i <= n);
          loop invariant (1 < \at(n, Pre)) ==> (((max == a[0])&&(i == 1)&&(n == \at(n, Pre))&&(a == \at(a, Pre))) || (\forall integer k; 0 <= k < i ==> max >= a[k]));
          loop invariant (!(1 < \at(n, Pre))) ==> ((max == a[0])&&(i == 1)&&(n == \at(n, Pre))&&(a == \at(a, Pre)));
          loop invariant n == \at(n, Pre);
          loop invariant a == \at(a, Pre);
            */
            while (i < n) {
    if (max < a[i])
    max = a[i];
    i = i + 1;
  }
            
  return max;
}
