
int unknown();

void foo() {
  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;

  /* >>> LOOP INVARIANT TO FILL <<< 
  >>> PRECONDITION OF THE LOOP : (y == 0) * (x == 0) * (z == 0) * (w == 1) <<< */

  /*@
    loop invariant x == y;
    loop invariant (z == 0 && w == 1) || (z == 1 && w == 0);
  */
  while(unknown()){
    if(w) {
      x++;
      w = !w;
    }
    if(!z) {
      y++; 
      z=!z;
    }
  }

  /*@ assert x == y; */
}
