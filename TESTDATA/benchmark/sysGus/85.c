void foo(int y,int z1,int z2,int z3) {

    int x = -15000;
  
    
    while (x < 0) {
      
      x  = x + y;
      y  = y + 1;
      
  
    }
    /*@ assert y > 0; */
  
  }