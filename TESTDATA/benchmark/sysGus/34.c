void foo(int n,int v1,int v2,int v3) {

    int x = n;
    
    
    while (x > 0) {
      
       x  = x - 1;
  
    }
  
   /*@ assert (n >= 0) ==> (x == 0); */
  }