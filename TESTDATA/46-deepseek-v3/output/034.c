
void foo(int n)
{
  int x=0;
  int y=0;
  int i=0;
  int m=10;
  
            /*@
          loop invariant (0 < \at(n, Pre)) ==> (((m == 10)&&(i == 0)&&(y == 0)&&(x == 0)&&(n == \at(n, Pre))) || (x == i));
          loop invariant (0 < \at(n, Pre)) ==> (((m == 10)&&(i == 0)&&(y == 0)&&(x == 0)&&(n == \at(n, Pre))) || (2*y <= i && i <= 2*y + 1));
          loop invariant (0 < \at(n, Pre)) ==> (((m == 10)&&(i == 0)&&(y == 0)&&(x == 0)&&(n == \at(n, Pre))) || (i <= n));
          loop invariant (!(0 < \at(n, Pre))) ==> ((m == 10)&&(i == 0)&&(y == 0)&&(x == 0)&&(n == \at(n, Pre)));
          loop invariant m == 10;
          loop invariant n == \at(n, Pre);
            */
            while(i < n) {
    i++;
    x++;
    if(i%2 == 0) y++;
  }
            
  
  /*@ assert (i == m) ==> (x == 2* y);*/
}
