
int unknown();

void foo(int i, int j) {
  
  int x = i;
  int y = j;
  
  /*@
    loop invariant x - y == i - j;
    loop invariant j == \at(j, Pre);
    loop invariant i == \at(i, Pre);
  */
  while(x != 0) {
    x--;
    y--;
  }

  /*@ assert (i == j) ==> (y == 0); */
}
