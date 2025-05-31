
int fun28(int x, int y , int *r) {
    *r = x;
    int d = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant (*\at(r, Pre) >= \at(y, Pre)) ==> ((*r % \at(y, Pre) == *\at(r, Pre) % \at(y, Pre)) && (d >= 0));
      loop invariant (*\at(r, Pre) >= \at(y, Pre)) ==> (0 <= d);
      loop invariant y == \at(y, Pre);
      loop invariant x == \at(x, Pre);
    */
    while (*r >= y) {
        *r = *r - y;
        d = d + 1;
    }
            
    return d;
}
