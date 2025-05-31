
int unknown1();
int unknown2();

void foo() {
  int a = 1;
  int b = 1;
  int c = 2;
  int d = 2;
  int x = 3;
  int y = 3;
  
  /*@
    loop invariant a + c == b + d;
    loop invariant a >= 0;
    loop invariant d >= 0;
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
      loop invariant a + c == b + d;
      loop invariant a >= 0;
      loop invariant d >= 0;
    */
    while (unknown2()) {
      c--;
      b--;
    }
  }
                
  /*@assert a + c == b + d; */
}
