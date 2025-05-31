
void foo() {
    int x = 100;
    
    
    
            
            /*@
          loop invariant  ((x == 100)) || (x >= 0 && x <= 100) ;
            */
            while (x > 0) {
      
      x  = x - 1;
      
    }
            
  
    /*@ assert x == 0; */
  }
