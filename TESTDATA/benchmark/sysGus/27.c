void foo(int n) {

    int x = n;
    
    
    while (x > 1) {
      
       x  = x - 1;
  
    }
  
   /*@ assert (n >= 1) ==> (x == 1); */
  }