
int unknown();

void foo(int flag) {
  int x = 1;
  int y = 1;
  int a;

  if (flag)
    a = 0;
  else
    a = 1;

  /*@ 
    loop invariant (flag ==> (a == x + y || a == x + y + 1)) && (!flag ==> (a == x + y + 1 || a == x + y + 2));
    loop invariant a % 2 == (flag ? 0 : 1);
    loop assigns x, y, a;
  */
  while (unknown()) {
    if (flag) {
      a = x + y;
      x++;
    } else {
      a = x + y + 1;
      y++;
    }
    if (a % 2 == 1)
      y++;
    else
      x++;
  }

  if (flag){
    a++;
  }
  /*@ assert a % 2 == 1; */
}
