
void foo(int y) {

    int x = -50;
  
    
    
                
                /*@
                  loop invariant x >= -50 && x <= \at(x, Pre) + (y - \at(y, Pre)) * (\at(y, Pre) + 1);
                  loop invariant y >= \at(y, Pre) && y <= \at(y, Pre) + (50 + \at(x, Pre));
                */
                while (x < 0) {
      
      x  = x + y;
      y  = y + 1;
      
  
    }
                
    /*@ assert y > 0; */
  
  }
