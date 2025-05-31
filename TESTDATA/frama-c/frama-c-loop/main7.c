

/*@
    requires \true; 
    ensures \result >= 0; // The result is always non-negative.
    ensures \result == (\at(x, Pre) >= 0 ? \at(x, Pre) : -\at(x, Pre)); // The result is the absolute value of the input.
*/
int test(int x) {
    int a = x;
    int y = 0;

    /*@
      loop invariant (\at(x, Pre) != 0) ==> (a + y == \at(x, Pre)); // Invariant: sum of `a` and `y` equals the original value of `x` if `x` is non-zero.
      loop invariant (\at(x, Pre) != 0) ==> (y >= 0); // Invariant: `y` is always non-negative if `x` is non-zero.
      loop invariant (!(\at(x, Pre) != 0)) ==> ((y == 0) && (a == \at(x, Pre)) && (x == \at(x, Pre))); // Invariant: If `x` is zero, `y` remains 0, and `a` and `x` are unchanged.
      loop invariant x == \at(x, Pre); // Invariant: `x` remains constant throughout the loop.
      loop assigns a, y; // Variables modified within the loop.
      loop variant a >= 0 ? a : -a; // Variant: Absolute value of `a` strictly decreases.
    */
    while(a != 0) {
        y = y + 1;
        a = a - 1;
    }
            
    return y;
}
int main7() {
    int num = test(3);
    //@ assert num == 3;
    return 0;
}