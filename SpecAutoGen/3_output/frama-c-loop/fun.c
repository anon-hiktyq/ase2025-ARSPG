
int fun(int x, int y) {
    int r = x;
    int d = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant (\at(x, Pre) >= \at(y, Pre)) ==> (r == \at(x, Pre) - d * \at(y, Pre)) ;
      loop invariant (\at(x, Pre) >= \at(y, Pre)) ==> (d >= 0) ;
      loop invariant (!(\at(x, Pre) >= \at(y, Pre))) ==> ((d == 0)&&(r == \at(x, Pre))&&(y == \at(y, Pre))&&(x == \at(x, Pre)));
      loop invariant y == \at(y, Pre);
      loop invariant x == \at(x, Pre);
    */
    while (r >= y) {
        // Beginning
        r = r - y;
        d = d + 1;
        // End
    }
            
    return d;
}
