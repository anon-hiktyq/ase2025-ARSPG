
void foo(int y) {

    int x = -50;
  
    /*@
      loop invariant x <= -50 + y * (y - \at(y, Pre));
      loop invariant y >= \at(y, Pre);
    */
    while (x < 0) {
      
      x = x + y;
      y = y + 1;
      
    }
            
    /*@ assert y > 0; */
  
}
