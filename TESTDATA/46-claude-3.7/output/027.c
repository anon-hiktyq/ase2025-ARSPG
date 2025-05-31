
/*@
requires l > 0;
*/
void foo(int l,int n) {
  int i, k;
 
  k = 1;
  
            
            /*@
          loop invariant  (\at(l, Pre) > 0) ==> ((1 < \at(n, Pre)) ==> (((k == 1)&&(n == \at(n, Pre))&&(l == \at(l, Pre))) || (1 < k && k < n))) ;
          loop invariant (\at(l, Pre) > 0) ==> ((!(1 < \at(n, Pre))) ==> ((k == 1)&&(n == \at(n, Pre))&&(l == \at(l, Pre))));
          loop invariant (\at(l, Pre) > 0) ==> (n == \at(n, Pre));
          loop invariant (\at(l, Pre) > 0) ==> (l == \at(l, Pre));
            */
            for (k = 1; k < n; k++) {
    i = l;
    
            
            /*@
          loop invariant l == \at(l, Pre);
          loop invariant n == \at(n, Pre);
          loop invariant l <= i <= n;
          loop invariant 1 <= k < n;
            */
            for (i = l; i < n; i++) {

    }
            

    /*@ assert \forall i; (l <= i < n) ==> (1 <= k); */
  }
            
}
