
void foo(int n)  {
  int i, j, k;

  i = 0;
  
  /*@
    loop invariant (0<\at(n, Pre)) ==> (0 <= i <= n+1); // Weakened invariant
    loop invariant (!(0<\at(n, Pre))) ==> ((i == 0)&&(n == \at(n, Pre)));
    loop invariant n == \at(n, Pre);
  */
  for (i = 0; i < n; i++) {

    j = i;
    
    /*@
      loop invariant n == \at(n, Pre);
      loop invariant 0 <= i <= n;
      loop invariant i <= j <= n;
    */
    for (j = i; j < n; j++) {

      k = j;

      /*@
        loop invariant n == \at(n, Pre);
        loop invariant 0 <= i < n;
        loop invariant i <= j < n;
        loop invariant j <= k <= n;
      */
      for (k = j; k < n; k++) {
        /*@assert k >= i;*/
      }

    }

  }
}
