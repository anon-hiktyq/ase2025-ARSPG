
void foo() {
  
    int i=1;
    int j=10;
   
                
                /*@
          loop invariant  j >= 0 && j <= 10 && j >= i - 5 ;
                */
                while (j >= i) {
      
      i  = i + 2;
      j  = j - 1;
      
  
    }
                
  
    /*@ assert j == 6;*/
  
  }
