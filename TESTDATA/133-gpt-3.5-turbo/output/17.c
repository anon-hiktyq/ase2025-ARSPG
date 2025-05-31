
int unknown();
void foo(int n)
{
    int x = 1;
    int m = 1;

            /*@
          loop invariant (1 < \at(n, Pre)) ==> (((m == 1)&&(x == 1)&&(n == \at(n, Pre))) || (m < n));
          loop invariant (1 < \at(n, Pre)) ==> (((m == 1)&&(x == 1)&&(n == \at(n, Pre))) || (x <= n));
          loop invariant !(1 < \at(n, Pre)) ==> ((m == 1)&&(x == 1)&&(n == \at(n, Pre)));
          loop invariant n == \at(n, Pre);
            */
            while (x < n) {
        
        if (unknown()) {
            m = x;
        }
        
        x = x + 1;
    }
            
 
    /*@ assert (n > 1) ==> (m < n); */

}
