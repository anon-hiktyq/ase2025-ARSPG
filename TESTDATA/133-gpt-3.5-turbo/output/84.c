
void foo(int y) {

    int x = -50;
  
    
    
            
            /*@          loop invariant  ((x == -50) && (y == \at(y, Pre))) || (x + y >= -50) ;
            */
            while (x < 0) {
      
      x  = x + y;
      y  = y + 1;
      
  
    }
            
    /*@ assert y > 0; */
  
}
