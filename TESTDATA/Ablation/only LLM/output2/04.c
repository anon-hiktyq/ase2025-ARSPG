
void foo(int x,int y) {
  x = -50;
  
  /*@ 
    loop invariant x < y;
    loop assigns x, y;
  */
  while( x < 0 ) {
	x = x + y;
	y++;
  }
  /*@ assert y > 0; */
}
