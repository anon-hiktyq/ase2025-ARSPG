
void foo(int x, int y) {

  x = -50;
  
  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : (y == \at(y, Pre)) * (x == -50) <<< */
    
  /*@    loop invariant  (y == \at(y, Pre) && x == -50) || (x < 0 && y >= 0) ;
  */
  while( x < 0 ) {
    x = x + y;
    y++;
  }
  
  /*@ assert y > 0;*/
}
