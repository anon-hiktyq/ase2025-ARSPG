
int unknown1();
int unknown2();
int unknown3();

void main() {
  int w = 1, z = 0, x = 0, y = 0;

  while (unknown1()) {

    /*@
      loop invariant w == z + 1;
      loop invariant x == y;
      loop invariant x >= 0;
      loop invariant y >= 0;
    */
    while (unknown2()) {
      if (w % 2 == 1)
        x++;
      if (z % 2 == 0)
        y++;
    }

    /*@
      loop invariant w == z + 1;
      loop invariant x == y;
      loop invariant x >= 0;
      loop invariant y >= 0;
    */
    while (unknown3()) {
      z = x + y;
      w = z + 1;
    }
  }
  /*@ assert x == y;*/
}
