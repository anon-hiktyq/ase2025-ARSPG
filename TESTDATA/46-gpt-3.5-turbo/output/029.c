
int unknown1();
int unknown2();

void foo() {
  int a = 1;
  int b = 1;
  int c = 2;
  int d = 2;
  int x = 3;
  int y = 3;

  /* >>> LOOP INVARIANT TO FILL <<< */
  
  /*@
    loop invariant  ((y == 3)&&(x == 3)&&(d == 2)&&(c == 2)&&(b == 1)&&(a == 1)) || (a + c == b + d);
    loop invariant  ((y == 3)&&(x == 3)&&(d == 2)&&(c == 2)&&(b == 1)&&(a == 1)) || (a >= 0 && d >= 0);
    loop invariant  ((y == 3)&&(x == 3)&&(d == 2)&&(c == 2)&&(b == 1)&&(a == 1)) || (x % 1 == (a + c) % 1);
    loop invariant  ((y == 3)&&(x == 3)&&(d == 2)&&(c == 2)&&(b == 1)&&(a == 1)) || (a >= 0);
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

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
       loop invariant a + c == b + d;
       loop invariant a >= 0 && d >= 0; 
    */
    while (unknown2()) {
      c--;
      b--;
    }
                
  }
                
  /*@assert a + c == b + d; */
}
