
void foo(int n,int v1,int v2,int v3) {
  
    int x = 0;
    
    /*@
      loop invariant (0 < \at(n, Pre)) ==> (((x == 0)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(n == \at(n, Pre))) || (x <= n));
      loop invariant (!(0 < \at(n, Pre))) ==> ((x == 0)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(n == \at(n, Pre)));
      loop invariant v3 == \at(v3, Pre);
      loop invariant v2 == \at(v2, Pre);
      loop invariant v1 == \at(v1, Pre);
      loop invariant n == \at(n, Pre);
    */
    while (x < n) {
      x  = (x + 1);
    }
            
    /*@ assert (x != n) ==> (n < 0); */
    
  }
