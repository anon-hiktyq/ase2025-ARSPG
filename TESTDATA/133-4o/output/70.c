
void foo(int n,int y,int v1,int v2,int v3) {
    
    int x = 1;

    /*@
      loop invariant (1 <= \at(n, Pre)) ==> (((x == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(y == \at(y, Pre))&&(n == \at(n, Pre))) || (y >= 0 && y <= n - 1));
      loop invariant (1 <= \at(n, Pre)) ==> (((x == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(y == \at(y, Pre))&&(n == \at(n, Pre))) || (x >= 1));
      loop invariant (!(1 <= \at(n, Pre))) ==> ((x == 1)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(y == \at(y, Pre))&&(n == \at(n, Pre)));
      loop invariant v3 == \at(v3, Pre);
      loop invariant v2 == \at(v2, Pre);
      loop invariant v1 == \at(v1, Pre);
      loop invariant n == \at(n, Pre);
    */
    while (x <= n) {
        y = n - x;
        x = x + 1;
    }

    /*@ assert (n > 0) ==> (y <= n); */
}
