
int unknown();
void foo(int n)
{
    int x = 0;
    int m = 0;

    
    
            
            /*@
          loop invariant (0 < \at(n, Pre)) ==> (((m == 0)&&(x == 0)&&(n == \at(n, Pre))) || (0 <= x));
          loop invariant (0 < \at(n, Pre)) ==> (((m == 0)&&(x == 0)&&(n == \at(n, Pre))) || (0 <= m <= x));
          loop invariant (0 < \at(n, Pre)) ==> (m < n);
          loop invariant (!(0 < \at(n, Pre))) ==> ((m == 0)&&(x == 0)&&(n == \at(n, Pre)));
          loop invariant n == \at(n, Pre);
            */
            while (x < n) {

        if (unknown()) {
            m = x;
        }
        
        x = x + 1;
    }
            

    /*@ assert (n > 0) ==> (m < n); */

}
