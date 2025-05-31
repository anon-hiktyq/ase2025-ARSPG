
void foo(int n)
{
  int x = 0;
  int y = 0;
  int i = 0;
  int m = 10;
  
  /*@ 
    loop invariant 0 <= i <= n;
    loop invariant x == i;
    loop invariant y == i / 2;
    loop assigns i, x, y;
    loop variant n - i;
  */
  while(i < n) {
    i++;
    x++;
    if(i % 2 == 0) y++;
  }
  
  /*@ assert (i == m) ==> (x == 2 * y); */
}
