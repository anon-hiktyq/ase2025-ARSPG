
void foo(){
  
    int x = 1;
    int y = 0;
    
    /*@ 
      loop invariant 0 <= y <= 100000;
      loop invariant x == 1 + (y * (y - 1)) / 2;
      loop variant 100000 - y;
    */
    while (y < 100000) {
      
       x  = x + y;
       y  = y + 1;
      
    }
  
    /*@ assert x >= y; */
}
