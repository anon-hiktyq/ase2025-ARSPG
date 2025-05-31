void foo(int n,int v1,int v2,int v3) {

    int x = n;
    
    
    while (x > 0) {
      
       x  = x - 1;
  
    }
  
   /*@ assert (x != 0) ==> (n < 0); */
  }