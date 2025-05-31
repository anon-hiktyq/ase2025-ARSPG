
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

  /*@    int j = w;
    int k = 0;
    
    /*@
      loop invariant i == z; // i starts from z
      loop invariant j == w; // j starts from w
      loop invariant 0 <= k; // k is initialized to 0 and incremented
      loop invariant i <= j; // since j is initialized to 0, i must be less than or equal to j
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
      loop invariant x >= z; // x is assigned from z
      loop invariant y >= 0; // y is manipulated based on k
      loop invariant z >= 0; // z is non-negative
      loop invariant j == 0; // j remains constant
      loop invariant w == x + y + 1; // w is based on x and y
      loop invariant i >= z; // i can be at least z at any point
      loop invariant k >= 0; // k is incremented
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
    w = x + y + 1; // w updates based on x and y
  }

  int c = 0;
  int d = 0;
  
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
  /*@ assert w >= z && a - b == 0; */
}
