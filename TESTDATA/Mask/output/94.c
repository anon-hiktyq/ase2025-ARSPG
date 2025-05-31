
/*@ requires n >= 0; 
    requires k >= 0;
*/
void foo(int n,int k) {
  
    int i = 0;
    int j = 0;
    
                
                /*@
          loop invariant (0 <= \at(n, Pre)) ==> (0 <= i <= n + 1);
          loop invariant (!(0 <= \at(n, Pre))) ==> ((j == 0)&&(i == 0)&&(k == \at(k, Pre))&&(n == \at(n, Pre)));
          loop invariant k == \at(k, Pre);
          loop invariant n == \at(n, Pre);
                */
                while (i <= n) {
      
       i  = i + 1;
       j  = j + i;
      
  
    }
                
    /*@ assert i + j + k > (2 * n); */;
  
  }
