
void foo(int x,int y) {
  x = -50;
  
  /*@    loop invariant ((y == \at(y, Pre)) && (x == -50)) || (y > \at(y, Pre));
  */
  while( x < 0 ) {
    x = x + y;
    y++;
  }
  
  /*@ assert y > 0; */
}
