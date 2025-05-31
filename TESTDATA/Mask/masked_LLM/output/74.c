
int unknown();
/*@ requires 0 <= y && y <= 127;
  @ ensures 0 <= c <= 36;
  @ ensures z == 36 * y + c;
*/
void foo(int y, int x1, int x2, int x3) {
  int c = 0;
  int z = 36 * y;

  /*@ loop invariant 0 <= c <= 36;
    @ loop invariant z == 36 * y + c;
    @ loop assigns c, z;
    @ loop variant c;
  */
  while (unknown()) {
    if (c < 36) {
      z = z + 1;
      c = c + 1;
    }
  }
}
