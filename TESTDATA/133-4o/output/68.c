
void foo(int n,int y) {
    
    int x = 1;

    /*@
      loop invariant (1 <= \at(n, Pre)) ==> (((x == 1)&&(y == \at(y, Pre))&&(n == \at(n, Pre))) || (0 <= y && y <= n));
      loop invariant (1 <= \at(n, Pre)) ==> (((x == 1)&&(y == \at(y, Pre))&&(n == \at(n, Pre))) || (x >= 1 && x <= n + 1));
      loop invariant (!(1 <= \at(n, Pre))) ==> ((x == 1)&&(y == \at(y, Pre))&&(n == \at(n, Pre)));
      loop invariant n == \at(n, Pre);
    */
    while (x <= n) {
        y = n - x;
        x = x + 1;
    }
            
    /*@ assert (n > 0) ==> (y <= n); */
}
