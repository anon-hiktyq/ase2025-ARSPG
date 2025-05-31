

/*@
requires n >= 0;
requires m >= 0;
requires m < n;
*/
void foo(int n, int m)
{
 
  int x = 0; 
  int y = m;
 
  while(x < n) {
    x++;
    if(x > m) y++;
  }
  /*@ assert y==n; */
}