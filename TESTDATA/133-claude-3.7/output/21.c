
int unknown();
void foo(int n,int z1,int z2,int z3)
{
    int x = 1;
    int m = 1;

    
    
            
            /*@
          loop invariant (1 < \at(n, Pre)) ==> (((m == 1)&&(x == 1)&&(z3 == \at(z3, Pre))&&(z2 == \at(z2, Pre))&&(z1 == \at(z1, Pre))&&(n == \at(n, Pre))) || ((x >= 1) && (x <= n)));
          loop invariant (1 < \at(n, Pre)) ==> (((m == 1)&&(x == 1)&&(z3 == \at(z3, Pre))&&(z2 == \at(z2, Pre))&&(z1 == \at(z1, Pre))&&(n == \at(n, Pre))) || ((m >= 1) && (m < x)));
          loop invariant (!(1 < \at(n, Pre))) ==> ((m == 1)&&(x == 1)&&(z3 == \at(z3, Pre))&&(z2 == \at(z2, Pre))&&(z1 == \at(z1, Pre))&&(n == \at(n, Pre)));
          loop invariant z3 == \at(z3, Pre);
          loop invariant z2 == \at(z2, Pre);
          loop invariant z1 == \at(z1, Pre);
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
