
/*@
requires l > 0;
*/
void foo(int l,int n) {
  int i, k;
 
  k = 1;
  
  /*@
    loop invariant l > 0;
    loop invariant 1 <= k;
    loop invariant n == \at(n, Pre);
    loop invariant l == \at(l, Pre);
  */
  for (k = 1; k < n; k++) {
    i = l;
    
    /*@
      loop invariant l == \at(l, Pre);
      loop invariant n == \at(n, Pre);
      loop invariant l <= i;
      loop invariant 1 <= k;
    */
    for (i = l; i < n; i++) {
    }
    
    /*@ assert \forall integer j; (l <= j < n) ==> (1 <= k); */
  }
}
