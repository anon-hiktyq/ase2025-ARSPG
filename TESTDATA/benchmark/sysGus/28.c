void foo(int n) {

    int x = n;
    
    
    while (x > 0) {
      
       x  = x - 1;
  
    }
  
   /*@ assert (x != 0) ==> (n < 0); */
  }