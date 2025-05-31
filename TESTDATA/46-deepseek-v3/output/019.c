
/*@
requires n >= 0;
requires m >= 0;
requires m < n;
*/
void foo(int n, int m)
{
 
  int x = 0; 
  int y = m;
 
  
            
            /*@
          loop invariant  (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> ((0 < \at(n, Pre)) ==> (((y == \at(m, Pre))&&(x == 0)&&(m == \at(m, Pre))&&(n == \at(n, Pre))) || (y == m + (x > m ? x - m : 0)))) ;
          loop invariant  (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> ((0 < \at(n, Pre)) ==> (((y == \at(m, Pre))&&(x == 0)&&(m == \at(m, Pre))&&(n == \at(n, Pre))) || (x >= 0 && x <= n))) ;
          loop invariant (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> ((!(0 < \at(n, Pre))) ==> ((y == \at(m, Pre))&&(x == 0)&&(m == \at(m, Pre))&&(n == \at(n, Pre))));
          loop invariant (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> (m == \at(m, Pre));
          loop invariant (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> (n == \at(n, Pre));
            */
            while(x < n) {
    x++;
    if(x > m) y++;
  }
            
  /*@ assert y==n; */
}
