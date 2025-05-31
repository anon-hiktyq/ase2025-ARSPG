
void foo(int y) {
    int x = 1;
    
    
    
    
            
            /*@
          loop invariant  ((x == 1)&&(y == \at(y, Pre))) || (y == 101 - x) ;
          loop invariant  ((x == 1)&&(y == \at(y, Pre))) || (x >= 2 && x <= 101) ;
            */
            while (x <= 100) {
        y = 100 - x;
        x = x +1;
    }
            

    /*@ assert (y >= 0); */

}
