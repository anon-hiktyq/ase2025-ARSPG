
int unknown();

/*@ requires m + 1 < n; */
void foo(int i,int j,int k,int n,int m) {

  i = 0;
  
            /*@          loop invariant  (\at(m, Pre) + 1 < \at(n, Pre)) ==> ((0 < \at(n, Pre)) ==> (((m == \at(m, Pre))&&(n == \at(n, Pre))&&(k == \at(k, Pre))&&(j == \at(j, Pre))&&(i == 0)) || (0 <= k <= j))) ;
          loop invariant (\at(m, Pre) + 1 < \at(n, Pre)) ==> ((!(0 < \at(n, Pre))) ==> ((m == \at(m, Pre))&&(n == \at(n, Pre))&&(k == \at(k, Pre))&&(j == \at(j, Pre))&&(i == 0)));
          loop invariant (\at(m, Pre) + 1 < \at(n, Pre)) ==> (m <= \at(m, Pre) + 4);
          loop invariant (\at(m, Pre) + 1 < \at(n, Pre)) ==> (n <= \at(n, Pre) + 4);
            */
            for (i = 0; i < n; i += 4) {
    j = i;
    
    /*@
      loop invariant 0 <= i < n;
      loop invariant 0 <= j <= m + 4;
      loop invariant 0 < n;
      loop invariant 0 <= m;
      loop invariant 0 <= k <= j;
    */
    for (j = i; j < m;) {
      
      if (unknown()) {
        /*@ assert j >= 0;*/
        j++;
        k = 0;
        
        /*@
          loop invariant 0 <= i < n;
          loop invariant 0 <= k <= j;
          loop invariant 0 < n;
          loop invariant 0 < m;
          loop invariant i <= j <= m + 4;
        */
        while (k < j) {
          k++;
        }
        
      } else {
        /*@ assert n + j + 5 > i;*/
        j += 2;
      }
    }
  }
            
}
