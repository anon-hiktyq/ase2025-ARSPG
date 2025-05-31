int unknown1();
int unknown2();

void foo() {
  int a = 1;
  int b = 1;
  int c = 2;
  int d = 2;
  int x = 3;
  int y = 3;

  /* >>> LOOP INVARIANT TO FILL <<< 
  >>> PRECONDITION OF THE LOOP : (y == 3) * (x == 3) * (d == 2) * (c == 2) * (b == 1) * (a == 1) <<< */
  
  /*@
    loop invariant a >= 1;
    loop invariant b >= 1;
    loop invariant c >= 0;
    loop invariant d >= 1;
    loop invariant x == a + c;
    loop invariant y == b + d;
  */
  while (unknown1()) {
    x = a + c;
    y = b + d;

    if ((x + y) % 2 == 0) {
      a++;
      d++;
    } else {
      a--;
    }

    /*@
      loop invariant c >= 0;
      loop invariant b >= 0;
    */
    while (unknown2()) {
      c--;
      b--;
    }
  }
  
  /*@assert a + c == b + d;*/
}


int unknown1();
int unknown2();

void foo() {
  int a = 1;
  int b = 1;
  int c = 2;
  int d = 2;
  int x = 3;
  int y = 3;

  /* >>> LOOP INVARIANT TO FILL <<< 
  >>> PRECONDITION OF THE LOOP : (y == 3) * (x == 3) * (d == 2) * (c == 2) * (b == 1) * (a == 1) <<< */
  
  /*@
    loop invariant a >= 1;
    loop invariant b >= 1;
    loop invariant c >= 0;
    loop invariant d >= 1;
    loop invariant x == a + c;
    loop invariant y == b + d;
  */
  while (unknown1()) {
    x = a + c;
    y = b + d;

    if ((x + y) % 2 == 0) {
      a++;
      d++;
    } else {
      a--;
    }

    /*@
      loop invariant c >= 0;
      loop invariant b >= 0;
    */
    while (unknown2()) {
      c--;
      b--;
    }
  }
  
  /*@assert a + c == b + d;*/
}
