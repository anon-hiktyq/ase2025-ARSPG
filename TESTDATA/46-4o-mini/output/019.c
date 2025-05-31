
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
          loop invariant  (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> (y == \at(m, Pre) + \max(0, x - \at(m, Pre)));
          loop invariant  (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> (x <= n);
          loop invariant  (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> (m == \at(m, Pre));
          loop invariant (\at(n, Pre) >= 0 && \at(m, Pre) >= 0 && \at(m, Pre) < \at(n, Pre)) ==> (n == \at(n, Pre));
            */
            while(x < n) {
    x++;
    if(x > m) y++;
  }
            
  /*@ assert y == n; */
}
