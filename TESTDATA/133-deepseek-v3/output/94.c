
/*@ requires n >= 0; 
    requires k >= 0;
*/
void foo(int n,int k) {
  
    int i = 0;
    int j = 0;
    
    
    
            
            /*@
          loop invariant  (\at(n, Pre) >= 0 && \at(k, Pre) >= 0) ==> ((0 <= \at(n, Pre)) ==> (((j == 0)&&(i == 0)&&(k == \at(k, Pre))&&(n == \at(n, Pre))) || (0 <= i <= n + 1 && j == i*(i + 1)/2))) ;
          loop invariant  (\at(n, Pre) >= 0 && \at(k, Pre) >= 0) ==> ((0 <= \at(n, Pre)) ==> (((j == 0)&&(i == 0)&&(k == \at(k, Pre))&&(n == \at(n, Pre))) || (0 <= i <= n + 1 && j == i*(i + 1)/2))) ;
          loop invariant (\at(n, Pre) >= 0 && \at(k, Pre) >= 0) ==> ((!(0 <= \at(n, Pre))) ==> ((j == 0)&&(i == 0)&&(k == \at(k, Pre))&&(n == \at(n, Pre))));
          loop invariant (\at(n, Pre) >= 0 && \at(k, Pre) >= 0) ==> (k == \at(k, Pre));
          loop invariant (\at(n, Pre) >= 0 && \at(k, Pre) >= 0) ==> (n == \at(n, Pre));
            */
            while (i <= n) {
      
       i  = i + 1;
       j  = j + i;
      
  
    }
            
    /*@ assert i + j + k > (2 * n); */;
  
  }
