
int unknown();

/*@ requires m + 1 < n; */
void foo(int i,int j,int k,int n,int m) {

  i = 0;
  
            
    /*@          loop invariant  (\at(m, Pre) + 1 < \at(n, Pre)) ==> ((0 < \at(n, Pre)) ==> (((m == \at(m, Pre))&&(n == \at(n, Pre))&&(k == \at(k, Pre))&&(j == \at(j, Pre))&&(i == 0)) || (k >= -1))) ;
          loop invariant (\at(m, Pre) + 1 < \at(n, Pre)) ==> ((!(0 < \at(n, Pre))) ==> ((m == \at(m, Pre))&&(n == \at(n, Pre))&&(k == \at(k, Pre))&&(j == \at(j, Pre))&&(i == 0)));
          loop invariant (\at(m, Pre) + 1 < \at(n, Pre)) ==> (m == \at(m, Pre));
          loop invariant (\at(m, Pre) + 1 < \at(n, Pre)) ==> (n == \at(n, Pre));
            */
            for (i = 0; i < n; i += 4) {
    j = i;
    
            
            /*@
          loop invariant 0 <= i < n;
          loop invariant i <= j && j < n;
          loop invariant k >= -1;
          loop invariant n == \at(n, Pre) && n > 0;
          loop invariant m == \at(m, Pre) && m + 1 < n;
            */
            for (j = i; j < m;) {
        
      if (unknown()) {
        /*@ assert j >= 0;*/
        j++;
        k = 0;
        
            
            /*@
          loop invariant 0 <= i < n;
          loop invariant 0 <= k <= j;
          loop invariant n == \at(n, Pre) && n > 0;
          loop invariant m == \at(m, Pre) && m > 0;
          loop invariant i <= j && j < n;
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
