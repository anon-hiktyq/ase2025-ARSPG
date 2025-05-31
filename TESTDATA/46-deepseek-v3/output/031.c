
int unknown();

/*@ requires m + 1 < n; */
void foo(int i,int j,int k,int n,int m) {

  i = 0;
  
            /*@
          loop invariant 0 <= i;
          loop invariant i <= j;
          loop invariant \at(k, Pre) <= k;
          loop invariant n == \at(n, Pre);
          loop invariant m == \at(m, Pre);
            */
            for (i = 0; i < n; i += 4) {
    j = i;
    
            /*@
          loop invariant 0 <= i <= n;
          loop invariant i <= j;
          loop invariant \at(k, Pre) <= k;
          loop invariant n == \at(n, Pre);
          loop invariant m == \at(m, Pre);
            */
            for (j = i; j < m;) {
        
      if (unknown()) {
        /*@ assert j >= 0;*/
        j++;
        k = 0;
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= k <= j;
          loop invariant n == \at(n, Pre);
          loop invariant m == \at(m, Pre);
          loop invariant i <= j;
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
