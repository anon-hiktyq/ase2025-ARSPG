
void foo(int x,int y) {

  x = -50;
  
  /* >>> LOOP INVARIANT TO FILL <<< */
  
  /*@
    loop invariant  ((y == \at(y, Pre))&&(x == -50)) || 
    (x == -50 + (y - \at(y, Pre)) * (\at(y, Pre) + y - 1) / 2);
    loop invariant  ((y == \at(y, Pre))&&(x == -50)) || 
    (y == \at(y, Pre) + (y - \at(y, Pre)));
  */
  while( x < 0 ) {
    x = x + y;
    y++;
  }
  
  /*@ assert y > 0;*/
}
