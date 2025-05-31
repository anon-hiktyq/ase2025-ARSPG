
int unknown();
/*@ requires 0 <= y && y <= 127; */
void foo(int y,int x1,int x2,int x3) {
  int c = 0;
  int z = 36 * y;

        /*@
          loop invariant  0 <= c && c <= 36 ;
          loop invariant  z == 36 * y + c ;
          loop invariant x3 == \at(x3, Pre);
          loop invariant x2 == \at(x2, Pre);
          loop invariant x1 == \at(x1, Pre);
          loop invariant y == \at(y, Pre);
        */
        while (unknown()) {

          if ( c < 36 )
          {
            z  = z + 1;
            c  = c + 1;
          }
        }
          /*@ assert  ( z < 0 && z >= 4608 ) ==> ( c >= 36 ); */  
}
