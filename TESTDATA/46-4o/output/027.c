
/*@
requires l > 0;
*/
void foo(int l,int n) {
  int i, k;

  k = 1;
  
                
                /*@
          loop invariant  (\at(l, Pre) > 0) ==> ((1 < \at(n, Pre)) ==> (1 <= k)) ;
          loop invariant (\at(l, Pre) > 0) ==> ((!(1 < \at(n, Pre))) ==> ((k == 1)&&(n == \at(n, Pre))&&(l == \at(l, Pre))));
          loop invariant l > 0 ;
                */
                for (k = 1; k < n; k++) {
    i = l;
    
                
                /*@
          loop invariant l > 0 ;
          loop invariant n > 1 ;
          loop invariant i >= l ;
          loop invariant 1 <= k ;
                */
                for (i = l; i < n; i++) {

    }
                

    /*@ assert \forall integer j; (l <= j < n) ==> (1 <= k); */
  }
}
