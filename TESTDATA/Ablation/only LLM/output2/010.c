
int unknown();

void foo() {

  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;

  /*@ loop invariant x - y == 0;
      loop invariant 0 <= x;
      loop invariant 0 <= y;
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
