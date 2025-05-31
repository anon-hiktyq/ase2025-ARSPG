

/*@
    requires y != 0; // Ensure the divisor is non-zero
    requires \valid(q); // Ensure the pointer 'q' is valid
    requires \valid(r); // Ensure the pointer 'r' is valid
    ensures *q == x / y; // Ensure the quotient is correctly computed
    ensures *r == x % y; // Ensure the remainder is correctly computed
*/
void div_rem(unsigned x, unsigned y, unsigned* q, unsigned* r) {
    *q = x / y;
    *r = x % y;
}
void main15() {
    unsigned q, r;
    div_rem(10, 3, &q, &r);
    //@ assert q == 3;
    //@ assert r == 1;
   
}