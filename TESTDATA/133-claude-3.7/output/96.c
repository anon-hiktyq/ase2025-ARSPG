
void foo(int x) {
    int i =0;
    int j =0;
    int y =1;
    
    
    
            
            /*@
          loop invariant (0 <= \at(x, Pre)) ==> (((y == 1)&&(j == 0)&&(i == 0)&&(x == \at(x, Pre))) || ((0 <= i <= x+1) && (j == i)));
          loop invariant (0 <= \at(x, Pre)) ==> (((y == 1)&&(j == 0)&&(i == 0)&&(x == \at(x, Pre))) || (j == i));
          loop invariant (!(0 <= \at(x, Pre))) ==> ((y == 1)&&(j == 0)&&(i == 0)&&(x == \at(x, Pre)));
          loop invariant y == 1;
          loop invariant x == \at(x, Pre);
            */
            while (i <= x) {
      
      i  = i + 1;
      j  = j + y;
  
    }
            
  
  /*@ assert (i != j) ==> (y != 1) ;*/
  
  }
