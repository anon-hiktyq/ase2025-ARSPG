
int unknown();
void foo(int n)
{
    int x = 1;
    int m = 1;
    
    /*@ loop invariant 1 <= x <= n;
        loop invariant (x == 1) ==> (m == 1);
        loop invariant (x > 1) ==> (m < x);
        loop invariant n > 1 ==> m < n;
        loop variant n - x;
    */
    while (x < n) {
        
        if (unknown()) {
            m = x;
        }
        
        x = x + 1;
    }
 
    /*@ assert (n > 1) ==> (m < n); */

}
