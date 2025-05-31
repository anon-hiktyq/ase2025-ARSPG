
int unknown();
/*@ requires 0 <= y && y <= 127; */
void foo(int y) {
  int c = 0;
  int z = 36 * y;
  
  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : 0 <= \at(y, Pre) && \at(y, Pre) <= 127 && (z == 36 * \at(y, Pre)) * (c == 0) * (y == \at(y, Pre)) <<< */
  
  /*@
    loop invariant  (0 <= \at(y, Pre) && \at(y, Pre) <= 127) ==> (((z == 36 * \at(y, Pre))&&(c == 0)&&(y == \at(y, Pre))) || (0 < c && c <= 36)) ;
    loop invariant  (0 <= \at(y, Pre) && \at(y, Pre) <= 127) ==> (((z == 36 * \at(y, Pre))&&(c == 0)&&(y == \at(y, Pre))) || (z == 36 * \at(y, Pre) + c)) ;
    loop invariant (0 <= \at(y, Pre) && \at(y, Pre) <= 127) ==> (y == \at(y, Pre));
  */
  while (unknown()) {
    if ( c < 36 )
    {
      z  = z + 1;
      c  = c + 1;
    }
  }
            
  /*@ assert  ( z < 0 && z >= 4608) ==> ( c >= 36 ); */
}
