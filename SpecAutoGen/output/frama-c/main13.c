
/*@
  requires \valid(a) && \valid(b) && \valid(r); // Ensure all pointers are valid
  ensures *a == \old(*a) && *b == \old(*b) && *r == \old(*r); // Ensure values pointed by a, b, r remain unchanged
  ensures \result == \old(*a) + \old(*b) + \old(*r); // Ensure result is the sum of the values pointed by a, b, r
*/
int add13(int *a, int *b, int *r) 
{
    return *a + *b + *r;
}

/*@
  ensures \result == 0; // Ensure main returns 0
*/
int main13() {
    int a = 24;
    int b = 32;
    int r = 12;
    int x;

    x = add13(&a, &b, &r);
    //@ assert x == a + b + r; // Assert that x is the sum of a, b, r
    //@ assert x == 68; // Assert that x equals 68

    x = add13(&a, &a, &a);
    //@ assert x == a + a + a; // Assert that x is three times a
    //@ assert x == 72; // Assert that x equals 72
    return 0;
}
