
/*@
  requires \valid(p) && \valid(q); // Ensure pointers p and q are valid before dereferencing
  ensures *p == \old(*p) && *q == \old(*q); // Ensure the values pointed by p and q remain unchanged
  ensures \result == \old(*p) + \old(*q); // Ensure the result is the sum of the original values pointed by p and q
*/
int add14(int *p, int *q) 
{
    return *p + *q;
}

/*@
  ensures \result == 0; // Ensure main14 returns 0
*/
int main14() {
    int a = 24;
    int b = 32;
    int x;

    x = add14(&a, &b);
    //@ assert x == a + b; // Assert that x is the sum of a and b
    //@ assert x == 56; // Assert that x equals 56

    x = add14(&a, &a);
    //@ assert x == a + a; // Assert that x is the sum of a and a
    //@ assert x == 48; // Assert that x equals 48
    return 0;
}
