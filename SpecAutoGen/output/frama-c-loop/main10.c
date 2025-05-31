

/*@
    requires \valid(&a) && \valid(&b); // Ensure pointers to a and b are valid
    ensures \result == (a >= 0 ? a * b : 0); // Ensure the result is the product of a and b if a is non-negative, otherwise 0
*/
int mul10(int a, int b) {
    int x = a, y = b, prod = 0;

    /*@
      loop invariant x >= 0 ==> prod == (a - x) * b; // Invariant for non-negative x
      loop invariant x < 0 ==> prod == 0; // Invariant for negative x
      loop invariant y == \at(b, Pre); // y remains constant
      loop invariant b == \at(b, Pre); // b remains constant
      loop invariant a == \at(a, Pre); // a remains constant
      loop variant x; // x is strictly decreasing
    */
    while(x >= 0) {
        prod = prod + y;
        x--;
    }
            
    return prod;
}
int main10() {
    int pdt = mul10(2, 5);
    //@ assert pdt == 10;
}