
void foo(int y,int z) {

    int x = 0;
    
    
    
            /*@
          loop invariant  ((x == 0) && (z == \at(z, Pre)) && (y == \at(y, Pre))) || (y == \min(\at(y, Pre), z)) ;
          loop invariant  ((x == 0) && (z == \at(z, Pre)) && (y == \at(y, Pre))) || (0 <= x && x <= 5) ;
          loop invariant z == \at(z, Pre);
            */
            while(x < 5) {
       x += 1;
       if( z <= y) {
          y = z;
       }
    }
            
   
   /*@ assert z >= y; */
}
