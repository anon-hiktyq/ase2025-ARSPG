
int unknown1();
int unknown2();
int unknown3();

void foo(int flag) {
  int x = 0;
  int y = 0;
  int j = 0;
  int i = 0;

  /*@
    loop invariant x == y;
    loop invariant i == x*(x+1)/2;
    loop invariant flag == 0 ==> j == y*(y+1)/2;
    loop invariant flag != 0 ==> j == y*(y+1)/2 + y;
    loop invariant flag == \at(flag, Pre);
   */
  while (unknown1()) {
    x++;
    y++;
    i += x;
    j += y;
    if (flag) {
      j += 1;
    }
  }
            
  if (j >= i)
    x = y;
  else
    x = y + 1;

  int w = 1;
  int z = 0;
  
  /*@
    loop invariant (w == 1 && z == 0 && x == y) || 
                   (w == z + 1 && z == x + y && x >= y && x <= y + 1);
    loop invariant x >= 0 && y >= 0;
    loop invariant i == 0;
    loop invariant j == 0;
    loop invariant flag == \at(flag, Pre);
   */
  while (unknown2()) {
    /*@
      loop invariant x >= y && x <= y + 1;
      loop invariant (w % 2 == 1) ==> (x == y + 1);
      loop invariant (w % 2 == 0) ==> (x == y);
      loop invariant z == x + y;
      loop invariant j == 0;
      loop invariant i == 0;
      loop invariant flag == \at(flag, Pre);
     */
    while (unknown3()) {
      if (w % 2 == 1)
        x++;
      if (z % 2 == 0)
        y++;
    }
    z = x + y;
    w = z + 1;
  }
  /*@ assert x == y; */
}
