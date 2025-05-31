
/*@ requires n >= 0; */
void foo(int n) {

    int x = 0;
  
    
    
            
            /*@
          loop invariant  (\at(n, Pre) >= 0) ==> ((0 < \at(n, Pre)) ==> (x >= 0 && x <= \at(n, Pre))) ; 
          loop invariant (\at(n, Pre) >= 0) ==> ((!(0 < \at(n, Pre))) ==> ((x == 0)&&(n == \at(n, Pre))));
          loop invariant (\at(n, Pre) >= 0) ==> (n == \at(n, Pre));
            */
            while (x < n) {
      {
       x  = x + 1;
      }
  
    }
            
    /*@ assert x == n; */
  
  }
