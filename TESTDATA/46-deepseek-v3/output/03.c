
/*@
requires l > 0;
requires n > l;
*/
void foo(int n, int l) {
  int i,k;

  k = 1;
  
            /*@
          loop invariant (\at(l, Pre) > 0 && \at(n, Pre) > \at(l, Pre)) ==> ((1<\at(n, Pre)) ==> (((k == 1)&&(l == \at(l, Pre))&&(n == \at(n, Pre))) || (1 <= k <= n))) ;
          loop invariant (\at(l, Pre) > 0 && \at(n, Pre) > \at(l, Pre)) ==> ((!(1<\at(n, Pre))) ==> ((k == 1)&&(l == \at(l, Pre))&&(n == \at(n, Pre))));
          loop invariant l > 0 && n > l;
          loop invariant n > l;
            */
            for (k=1; k<n; k++){
  	i = l;
    
            /*@
          loop invariant 1 < n ;
          loop invariant l > 0 && l < n ;
          loop invariant i >= l ;
          loop invariant 1 <= k < n ;
            */
            for (i=l; i<n; i++) {
    }
    }
  
    /*@ assert \forall integer i; (l <= i < n)==> (1 <= i); */
}
