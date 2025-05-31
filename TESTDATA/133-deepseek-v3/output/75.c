
int unknown();
/*@ requires 0 <= y && y <= 127; */
void foo(int y,int x1,int x2,int x3) {
  int c = 0;
  int z = 36 * y;
  
            /*@
          loop invariant  (0 <= \at(y, Pre) && \at(y, Pre) <= 127) ==> (((z == 36 * \at(y, Pre))&&(c == 0)&&(x3 == \at(x3, Pre))&&(x2 == \at(x2, Pre))&&(x1 == \at(x1, Pre))&&(y == \at(y, Pre))) || (c <= 36)) ;
          loop invariant  (0 <= \at(y, Pre) && \at(y, Pre) <= 127) ==> (((z == 36 * \at(y, Pre))&&(c == 0)&&(x3 == \at(x3, Pre))&&(x2 == \at(x2, Pre))&&(x1 == \at(x1, Pre))&&(y == \at(y, Pre))) || (z == 36 * y + c)) ;
          loop invariant (0 <= \at(y, Pre) && \at(y, Pre) <= 127) ==> (x3 == \at(x3, Pre));
          loop invariant (0 <= \at(y, Pre) && \at(y, Pre) <= 127) ==> (x2 == \at(x2, Pre));
          loop invariant (0 <= \at(y, Pre) && \at(y, Pre) <= 127) ==> (x1 == \at(x1, Pre));
          loop invariant (0 <= \at(y, Pre) && \at(y, Pre) <= 127) ==> (y == \at(y, Pre));
          loop invariant 0 <= y;
          loop invariant z >= 36 * y;
            */
            while (unknown()) {
    if ( c < 36 )
    {
    z  = z + 1;
    c  = c + 1;
    }
  }
            
    /*@ assert  ( c < 36 ) ==> ( z >= 0 ) ; */
}
