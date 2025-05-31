
void foo() {

    int x = 1;
    int y = 0;
  
    
    
            
            /*@
          loop invariant  ((y == 0)&&(x == 1)) || (x == 1 + (y * (y - 1)) / 2);
          loop invariant  ((y == 0)&&(x == 1)) || (0 <= y <= 1000);
            */
            while (y < 1000) {
      
       x  = x + y;
       y  = y + 1;
      
    }
            
    
    /*@ assert x >= y; */
}
