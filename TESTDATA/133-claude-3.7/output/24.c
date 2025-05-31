
void foo() {
  
    int i=1;
    int j=10;
   
    
    
            
            /*@
          loop invariant  ((j == 10)&&(i == 1)) || ((i % 2 == 1) && (i >= 1)) ;
          loop invariant  ((j == 10)&&(i == 1)) || ((j <= 10) && (2*j + i == 21)) ;
          loop invariant j >= 6;
            */
            while (j >= i) {
      
      i  = i + 2;
      j  = j - 1;
      
  
    }
            
  
    /*@ assert j == 6;*/
  
  }
