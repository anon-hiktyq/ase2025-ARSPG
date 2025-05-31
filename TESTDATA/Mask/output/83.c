
void foo(int y) {

    int x = -5000;
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant y >= \at(y, Pre);
    */
    while (x < 0) {
      
      x = x + y;
      y = y + 1;
      
    }
                
    /*@ assert y > 0; */
  
}
