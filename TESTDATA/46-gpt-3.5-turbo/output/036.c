
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

  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : (w == 0) * (j == 0) * (z == 0) * (y == 0) * (x == 0) * (b == 0) * (a == 0) * (flag == \at(flag, Pre)) <<< */
    
  /*@
    loop invariant (0 <= x);
    loop invariant (y >= -1);
    loop invariant (0 <= z);
    loop invariant (j == 0);
    loop invariant (w == 0);
  */
  
  while (unknown1()) {
    int i = z;
    int j = w;
    int k = 0;
    
    /*@
      loop invariant flag == \at(flag, Pre);
      loop invariant a == 0;
      loop invariant b == 0;
      loop invariant x >= 0;
      loop invariant y >= 0;
      loop invariant z >= 0;
      loop invariant (j == 0);
      loop invariant (w == 0);
      loop invariant i >= 0;
      loop invariant k >= 0;
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

    /* >>> LOOP INVARIANT TO FILL <<< 
       >>> PRECONDITION OF THE LOOP : 0 % 2 == 1 && 0 >= 0 && retval_57 != 0 && retval_57 <= INT_MAX && retval_57 > INT_MIN && (k == 0) * (j == 0) * (i == 0) * (w == 0) * (#j == 0) * (z == 0) * (y == 0 - 1) * (x == 0 + 1) * (b == 0) * (a == 0) * (flag == \at(flag, Pre)) <<< */
    
    /*@
      loop invariant flag == \at(flag, Pre);
      loop invariant a == 0;
      loop invariant b == 0;
      loop invariant x >= 0;
      loop invariant y >= -1;
      loop invariant z >= 0;
      loop invariant (j == 0);
      loop invariant (w == 0);
      loop invariant i >= 0;
      loop invariant k >= 0;
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

  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : exists retval_57, retval_57 == 0 && retval_57 <= INT_MAX && retval_57 > INT_MIN && (d == 0) * (c == 0) * (w == 0) * (j == 0) * (z == 0) * (y == 0) * (x == 0) * (b == 0) * (a == 0) * (flag == \at(flag, Pre)) <<< */
    
  /*@
    loop invariant ((d == 0) && (c == 0) && (w == 0) && (j == 0) && (z == 0) && (y == 0) && (x == 0) && (b == 0) && (a == 0) && (flag == \at(flag, Pre))) || (c >= 0);
    loop invariant ((d == 0) && (c == 0) && (w == 0) && (j == 0) && (z == 0) && (y == 0) && (x == 0) && (b == 0) && (a == 0) && (flag == \at(flag, Pre))) || (d >= 0);
    loop invariant ((d == 0) && (c == 0) && (w == 0) && (j == 0) && (z == 0) && (y == 0) && (x == 0) && (b == 0) && (a == 0) && (flag == \at(flag, Pre))) || (a >= 0);
    loop invariant ((d == 0) && (c == 0) && (w == 0) && (j == 0) && (z == 0) && (y == 0) && (x == 0) && (b == 0) && (a == 0) && (flag == \at(flag, Pre))) || (b >= 0);
    loop invariant (w == 0);
    loop invariant (j == 0);
    loop invariant (z == 0);
    loop invariant (y == 0);
    loop invariant (x == 0);
    loop invariant (flag == \at(flag, Pre));
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
