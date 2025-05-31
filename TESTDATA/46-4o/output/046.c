
int unknown();

void foo() {

  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;

  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : (y == 0) * (x == 0) * (z == 0) * (w == 1) <<< */
    
  /*@
    loop invariant  ((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (w % 2 == 0) ;
    loop invariant  ((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (z % 2 == 1) ;
    loop invariant  ((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (x <= 1) ;
    loop invariant  ((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (y >= 0) ;
  */
  while (unknown()) {
    if (w % 2 == 1) {
      x++;
      w++;
    }
    if (z % 2 == 0) {
      y++;
      z++;
    }
  }

  /*@ assert x <= 1; */

}
