
int unknown1();
int unknown2();
int unknown3();

void foo(int flag) {
  int x = 0;
  int y = 0;
  int j = 0;
  int i = 0;

  /*@
    loop invariant  ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (x == y);
    loop invariant  ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (i >= 0); 
    loop invariant  ((i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (j >= 0); 
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

  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : exists retval_48, 0 >= 0 && retval_48 == 0 && retval_48 <= INT_MAX && retval_48 > INT_MIN && (z == 0) * (w == 1) * (i == 0) * (j == 0) * (y == 0) * (x == 0) * (flag == \at(flag, Pre)) <<< */

          /*@
        loop invariant  ((z == 0)&&(w == 1)&&(i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (x == y); 
        loop invariant  ((z == 0)&&(w == 1)&&(i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (y >= 0); 
        loop invariant  ((z == 0)&&(w == 1)&&(i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (x >= 0);
        loop invariant  ((z == 0)&&(w == 1)&&(i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (w == z + 1);
        loop invariant  ((z == 0)&&(w == 1)&&(i == 0)&&(j == 0)&&(y == 0)&&(x == 0)&&(flag == \at(flag, Pre))) || (z >= 0);
        loop invariant i >= 0;
        loop invariant j >= 0;
        loop invariant flag == \at(flag, Pre);
        */
        while (unknown2()) {
          
          /*@
        loop invariant flag == \at(flag, Pre);
        loop invariant x == y;
        loop invariant y >= 0;
        loop invariant x >= 0;
        loop invariant j >= 0;
        loop invariant i >= 0;
        loop invariant w == z + 1;
        loop invariant z >= x + y; 
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
