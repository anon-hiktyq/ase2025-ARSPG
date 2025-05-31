
int unknown1();
int unknown2();
int unknown3();

void foo(int flag) {
  int x = 0;
  int y = 0;
  int j = 0;
  int i = 0;
  
  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : (i == 0) * (j == 0) * (y == 0) * (x == 0) * (flag == \at(flag, Pre)) <<< */
  
  /*@
    loop invariant ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (i == x * (x + 1) / 2);
    loop invariant ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (j >= i);
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
    loop invariant x == y;
    loop invariant flag == \at(flag, Pre);
  */
  while (unknown2()) {
    /*@
      loop invariant x >= 0;
      loop invariant y >= 0;
      loop invariant w % 2 == z % 2;
      loop invariant z == x + y;
      loop invariant i == 0;
      loop invariant j == 0;
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
