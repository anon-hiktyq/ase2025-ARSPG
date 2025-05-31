
int arrayInit(int *a,int n) {
    int j =0;
    int i = 0;
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant \forall int k; 0 <= k < i ==> a[k] == k;
      loop invariant (0 < \at(n, Pre)) ==> (((i == 0)&&(j == 0)&&(n == \at(n, Pre))&&(a == \at(a, Pre))) || (j == 10));
      loop invariant (0 < \at(n, Pre)) ==> (0 <= i <= n);
      loop invariant (!(0 < \at(n, Pre))) ==> ((i == 0)&&(j == 0)&&(n == \at(n, Pre))&&(a == \at(a, Pre)));
      loop invariant n == \at(n, Pre);
      loop invariant a == \at(a, Pre);
    */
    for (; i < n; ++i) {
        a[i] = i;
        j =10;
    }
    
    return 0;
}
