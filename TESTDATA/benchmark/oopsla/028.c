int unknown();





void foo() {
  int x = 0;
  int y = 0;
  int n = 0;
 
  while(unknown()) {
      x++;
      y++;
  }
 
  while(x!=n) {
      x--;
      y--;
  }
  /*@ assert y == n; */
}
