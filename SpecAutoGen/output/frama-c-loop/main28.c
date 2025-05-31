
/*@
    requires \valid(r); // Ensure the pointer 'r' is valid
    requires y > 0; // Ensure the divisor 'y' is positive
    ensures \result >= 0; // Ensure the quotient is non-negative
    ensures *r >= 0 && *r < y; // Ensure the remainder is non-negative and less than the divisor
    ensures x == \result * y + *r; // Ensure the result satisfies the division equation
*/
int fun28(int x, int y, int *r) {
    *r = x;
    int d = 0;

    /*@
      loop invariant \valid(r); // Ensure the pointer 'r' remains valid
      loop invariant y > 0; // Ensure the divisor 'y' remains positive
      loop invariant *r >= 0; // Ensure the remainder is non-negative
      loop invariant x == d * y + *r; // Ensure the division equation holds at each iteration
      loop invariant d >= 0; // Ensure the quotient is non-negative
      loop assigns *r, d; // Specify the variables modified in the loop
      loop variant *r; // Ensure the loop progresses by decreasing the value of '*r'
    */
    while (*r >= y) {
        *r = *r - y;
        d = d + 1;
    }
            
    return d;
}

/*@
    ensures \result == 0; // Ensure the function returns 0
    ensures a == 1; // Ensure the value of 'a' is 1 after the function call
*/
int main28() {
    int a = 3;
    int num = fun28(1, 2, &a);
    //@ assert a == 1;
    //@ assert num == 0;
    return 0;
}
