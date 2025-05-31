
/*@
requires l > 0;
requires n > l;
*/
void foo(int n, int l) {
  int i,k;

  k = 1;
  
            /*@
          loop invariant  (\at(l, Pre) > 0 && \at(n, Pre) > \at(l, Pre)) ==> ((1<\at(n, Pre)) ==> (((k == 1)&&(l == \at(l, Pre))&&(n == \at(n, Pre))) || (0 < k && k <= \at(n, Pre)))) ;
          loop invariant (\at(l, Pre) > 0 && \at(n, Pre) > \at(l, Pre)) ==> ((!(1<\at(n, Pre))) ==> ((k == 1)&&(l == \at(l, Pre))&&(n == \at(n, Pre))));
          loop invariant (\at(l, Pre) > 0 && \at(n, Pre) > \at(l, Pre)) ==> (l == \at(l, Pre));
          loop invariant (\at(l, Pre) > 0 && \at(n, Pre) > \at(l, Pre)) ==> (n == \at(n, Pre));
            */
            for (k=1; k<n; k++){
  	i = l;
    
            /*@
          loop invariant n == \at(n, Pre);
          loop invariant l == \at(l, Pre);
          loop invariant l <= i <= n;
          loop invariant 1 <= k < n;
            */
            for (i=l; i<n; i++) {
    }
            

    }
            
  
    /*@ assert \forall integer i; (l <= i < n)==> (1 <= i); */
  

}
