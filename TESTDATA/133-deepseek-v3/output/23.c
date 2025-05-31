
void foo() {
  
    int i=1;
    int j=20;
   
    
    
            
            /*@
          loop invariant i + 2*j == 41;
          loop invariant 1 <= i <= 41;
          loop invariant 0 <= j <= 20;
          loop invariant i == 2*(20 - j) + 1;
          loop invariant j >= i ==> i + 2*j == 41;
          loop invariant j < i ==> j == 13;
            */
            while (j >= i) {
      
      i  = i + 2;
      j  = j - 1;
      
  
    }
            
  
    /*@ assert j == 13;*/
  
  }
