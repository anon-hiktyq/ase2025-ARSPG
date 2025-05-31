
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
    loop invariant a == 0 && b == 0;
    loop invariant flag == \at(flag, Pre);
    loop invariant (w == 0 && x == 0 && y == 0 && z == 0) || 
                  (w >= x + y && w <= x + y + 2);
    loop invariant j == w;
    loop invariant z >= 0;
    loop invariant (x >= 0) && (y >= -1);
    loop invariant x + y >= z - 1;
   */
  while (unknown1()) {
    int i = z;
    int j = w;
    int k = 0;
    
    /*@
      loop invariant flag == \at(flag, Pre);
      loop invariant a == 0 && b == 0;
      loop invariant i >= z && i <= j;
      loop invariant k == i - z;
      loop invariant j == w;
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
      loop invariant a == 0 && b == 0;
      loop invariant x >= 0;
      loop invariant y >= -2;
      loop invariant x + y >= z - (x % 2) - 1;
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
    loop invariant a == b;
    loop invariant c == d;
    loop invariant (flag != 0) ==> (a == c && b == d);
    loop invariant (flag == 0) ==> (a == b && c == d);
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
  
  /*@ assert w >= z && a == b;*/
}
