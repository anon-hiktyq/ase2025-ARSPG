
int unknown();

void foo() {
  int x = 0;
  int y = 0;
  int n = 0;

  /*@ 
    loop invariant  ((n == 0)&&(y == 0)&&(x == 0)) || (x == y);
    loop invariant  ((n == 0)&&(y == 0)&&(x == 0)) || (x >= 0 && y >= 0);
    loop invariant n == 0;
  */
  while(unknown()) {
    x++;
    y++;
  }

  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : exists retval_32, retval_32 == 0 && retval_32 <= INT_MAX && retval_32 > INT_MIN && (n == 0) * (y == 0) * (x == 0) <<< */
    
  /*@
    loop invariant  ((n == 0)&&(y == 0)&&(x == 0)) || (x == y);
    loop invariant  ((n == 0)&&(y == 0)&&(x == 0)) || (x >= 0 && y >= 0);
    loop invariant n == 0;
  */
  while(x != n) {
    x--;
    y--;
  }
  
  /*@ assert y == n; */
}
