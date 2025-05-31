
int unknown();
void foo(int n,int z1,int z2,int z3)
{
    int x = 1;
    int m = 1;

    /*@ 
      loop invariant 1 <= x <= n;
      loop invariant m < x;
      loop assigns x, m;
      loop variant n - x;
    */
    while (x < n) {

        if (unknown()) {
            m = x;
        }
        
        x = x + 1;
    }

    /*@ assert (n > 0) ==> (m < n); */
}
