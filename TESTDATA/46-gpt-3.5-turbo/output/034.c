
void foo(int n)
{
  int x=0;
  int y=0;
  int i=0;
  int m=10;
  
 
  
            
            /*@
          loop invariant (0 < \at(n, Pre)) ==> (((m == 10)&&(i == 0)&&(y == 0)&&(x == 0)&&(n == \at(n, Pre))) || (i >= 0 && x == i && y == i / 2));
          loop invariant (0 < \at(n, Pre)) ==> (((m == 10)&&(i == 0)&&(y == 0)&&(x == 0)&&(n == \at(n, Pre))) || (i >= 0 && x == i && y == i / 2));
          loop invariant (0 < \at(n, Pre)) ==> (((m == 10)&&(i == 0)&&(y == 0)&&(x == 0)&&(n == \at(n, Pre))) || (i >= 0 && x == i && y == i / 2));
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
