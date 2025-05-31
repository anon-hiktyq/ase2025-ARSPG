

/*@
    requires y > 0; // Ensure the divisor is positive
    requires x >= 0; // Ensure the dividend is non-negative
    ensures \result >= 0; // Ensure the result (quotient) is non-negative
    ensures x == \result * y + \result; // Ensure the dividend is equal to quotient * divisor + remainder
    ensures \result == x / y; // Ensure the result matches the integer division of x by y
*/
int fun(int x, int y) {
    int r = x;
    int d = 0;

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
int main24() {
    int a = fun(10);
    //@ assert a == 3;
}