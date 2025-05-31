
int unknown();
/*@ requires x >= 0 && x <= 2 && y <= 2 && y >= 0; */
void foo(int x,int y) {

            /*@
          loop invariant  (\at(x, Pre) >= 0 && \at(x, Pre) <= 2 && \at(y, Pre) <= 2 && \at(y, Pre) >= 0) ==> (((y == \at(y, Pre))&&(x == \at(x, Pre))) || (x <= 2 + 2 * (y) && y <= 2 + 2 * (y))) ;
          loop invariant  (\at(x, Pre) >= 0 && \at(x, Pre) <= 2 && \at(y, Pre) <= 2 && \at(y, Pre) >= 0) ==> (((y == \at(y, Pre))&&(x == \at(x, Pre))) || (y <= 2 + 2 * (x) && x <= 2 + 2 * (x))) ;
            */
            while (unknown()) {
      
      x  = x + 2;
      y  = y + 2;

    }
            
      /*@ assert (y == 0) ==> (x != 4);  */
  
}
