
int unknown();

/*@ requires n >= 0; */
void foo(int n) {
  
    int i = 0;
    int x = 0;
    int y = 0;
    
  
    
    /*@
      loop invariant  (\at(n, Pre) >= 0) ==> ((0 < \at(n, Pre)) ==> (((y == 0)&&(x == 0)&&(i == 0)&&(n == \at(n, Pre))) || (x + y == 3 * i))) ;
      loop invariant  (\at(n, Pre) >= 0) ==> ((0 < \at(n, Pre)) ==> (((y == 0)&&(x == 0)&&(i == 0)&&(n == \at(n, Pre))) || (i <= n))) ;
      loop invariant  (\at(n, Pre) >= 0) ==> ((0 < \at(n, Pre)) ==> (((y == 0)&&(x == 0)&&(i == 0)&&(n == \at(n, Pre))) || (x + y == 3 * i))) ;
      loop invariant (\at(n, Pre) >= 0) ==> ((!(0 < \at(n, Pre))) ==> ((y == 0)&&(x == 0)&&(i == 0)&&(n == \at(n, Pre))));
      loop invariant (\at(n, Pre) >= 0) ==> (n == \at(n, Pre));
    */
    while (i < n) {
      
        i  = i + 1;
        if (unknown()) {
          
          x  = x + 1;
          y  = y + 2;
          
        } else {
          
          x  = x + 2;
          y  = y + 1;
          
        }
  
  
    }
            
  
    /*@ assert (3 * n) == (x + y); */
  
}
