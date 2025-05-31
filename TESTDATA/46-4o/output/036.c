
int unknown1();
int unknown2();
int unknown3();

void foo(int flag) {
  int a = 0;
  int b = 0;
  int x = 0;
  int y = 0;
  int z = 0;
  int j = 0;
  int w = 0;

  /*@
    loop invariant flag == \at(flag, Pre);
    loop invariant a == 0;
    loop invariant b == 0;
    loop invariant y >= 0;
    loop invariant z >= 0;
    loop invariant w >= z;
    loop invariant x >= y;
  */
  
  while (unknown1()) {
    int i = z;
    int j = w;
    int k = 0;

    /*@
      loop invariant flag == \at(flag, Pre);
      loop invariant a == 0;
      loop invariant b == 0;
      loop invariant y >= 0;
      loop invariant z >= 0;
      loop invariant w >= z;
      loop invariant x >= y;
    */
    while (i < j) {
      k++;
      i++;
    }

    x = z;
    y = k;

    if (x % 2 == 1) {
      x++;
      y--;
    }

    /*@
      loop invariant flag == \at(flag, Pre);
      loop invariant a == 0;
      loop invariant b == 0;
      loop invariant y >= 0;
      loop invariant z >= 0;
      loop invariant w >= z;
      loop invariant x >= y;
    */
    while (unknown2()) {
      if (x % 2 == 0) {
        x += 2;
        y -= 2;
      } else {
        x--;
        y--;
      }
    }

    z++;
    w = x + y + 1;
  }
            
  int c = 0;
  int d = 0;
  
  /*@
    loop invariant c >= 0;
    loop invariant d >= 0;
    loop invariant a == c;
    loop invariant b == d;
    loop invariant flag == \at(flag, Pre);
  */
  while (unknown3()) {
    c++;
    d++;
    if (flag) {
      a++;
      b++;
    } else {
      a += c;
      b += d;
    }
  }
  
  /*@ assert w >= z && a - b == 0;*/
}
