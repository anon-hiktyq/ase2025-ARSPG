
#include <assert.h>

int unknown();

void foo(int flag) {
  int x = 1;
  int y = 1;
  int a;

  if (flag)
    a = 0;
  else
    a = 1;

  /*@
    loop invariant  (\at(flag, Pre) == 0) ==> (((a == 1)&&(y == 1)&&(x == 1)&&(flag == \at(flag, Pre))) || ((a == x + y + 1 || a == x + y) && x >= 1 && y > 1)) ;
    loop invariant  (\at(flag, Pre) == 0) ==> (((a == 1)&&(y == 1)&&(x == 1)&&(flag == \at(flag, Pre))) || (y > 1)) ;
    loop invariant  (\at(flag, Pre) == 0) ==> (((a == 1)&&(y == 1)&&(x == 1)&&(flag == \at(flag, Pre))) || (a == x + y + 1 || a == x + y)) ;
    loop invariant (\at(flag, Pre) == 0) ==> (flag == \at(flag, Pre));
    loop invariant  (\at(flag, Pre) != 0) ==> (((a == 0)&&(y == 1)&&(x == 1)&&(flag == \at(flag, Pre))) || ((a == x + y || a == x + y + 1) && x > 1 && y >= 1)) ;
    loop invariant  (\at(flag, Pre) != 0) ==> (((a == 0)&&(y == 1)&&(x == 1)&&(flag == \at(flag, Pre))) || (x > 1)) ;
    loop invariant  (\at(flag, Pre) != 0) ==> (((a == 0)&&(y == 1)&&(x == 1)&&(flag == \at(flag, Pre))) || (a == x + y || a == x + y + 1)) ;
    loop invariant (\at(flag, Pre) != 0) ==> (flag == \at(flag, Pre));
  */
  while (unknown()) {
    if (flag) {
      a = x + y;
      x++;
    } else {
      a = x + y + 1;
      y++;
    }
    if (a % 2 == 1)
      y++;
    else
      x++;
  }

  if (flag){
    a++;
  }
  /*@ assert a % 2 == 1; */
}
