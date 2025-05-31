
void foo(int x,int y) {

  x = -50;
  
  /*@
    loop invariant x <= -50 + y * (y - \at(y, Pre));
    loop invariant y >= \at(y, Pre);
  */
  while( x < 0 ) {
    x = x + y;
    y++;
  }
  
  /*@ assert y > 0;*/
}
