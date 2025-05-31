
void foo(int n)
{
  int x=0;
  int y=0;
  int i=0;
  
  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : (i == 0) * (y == 0) * (x == 0) * (n == \at(n, Pre)) <<< */

  /*@
    loop invariant (0<\at(n, Pre)) ==> (((i == 0)&&(y == 0)&&(x == 0)&&(n == \at(n, Pre))) || (x == i));
    loop invariant (0<\at(n, Pre)) ==> (((i == 0)&&(y == 0)&&(x == 0)&&(n == \at(n, Pre))) || (y == i / 2));
    loop invariant (0<\at(n, Pre)) ==> (((i == 0)&&(y == 0)&&(x == 0)&&(n == \at(n, Pre))) || (0 <= i <= n));
    loop invariant (!(0<\at(n, Pre))) ==> ((i == 0)&&(y == 0)&&(x == 0)&&(n == \at(n, Pre)));
    loop invariant n == \at(n, Pre);
  */
  while(i<n) {
    i++;
    x++;
    if(i%2 == 0) y++;
  }
  
  /*@assert (i%2 == 0) ==> (x==2*y); */
}
