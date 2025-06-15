
/*@
  requires \valid(a) && \valid(b) && \valid(r); // Ensure all pointers are valid before dereferencing.
  ensures *a == \old(*a) && *b == \old(*b) && *r == \old(*r); // Ensure the values of the pointers remain unchanged.
  ensures \result == \old(*a) + \old(*b) + \old(*r); // Ensure the result is the sum of the original values of the pointers.
*/
int add13(int *a, int *b, int *r) 
{
    return *a + *b + *r;
}

/*@
  ensures \result == 0; // Ensure the main function returns 0.
*/
int main13() {
    int a = 24;
    int b = 32;
    int r = 12;
    int x;

    x = add13(&a, &b, &r);
    //@ assert x == a + b + r; // Assert that x equals the sum of a, b, and r.
    //@ assert x == 68; // Assert that x equals 68.

    x = add13(&a, &a, &a);
    //@ assert x == a + a + a; // Assert that x equals the sum of a, a, and a.
    //@ assert x == 72; // Assert that x equals 72.

    return 0;
}
