
/*@

  requires \valid(a) && \valid(b); // Ensure both pointers are valid
  ensures (\old(*a) < \old(*b)) ==> (*a == \old(*a) && *b == \old(*b)); // If *a < *b, then the values remain unchanged
  ensures (\old(*a) < \old(*b)) ==> (\result == \old(*b)); // If *a < *b, result is *b
  ensures (\old(*a) >= \old(*b)) ==> (*a == \old(*a) && *b == \old(*b)); // If *a >= *b, then the values remain unchanged
  ensures (\old(*a) >= \old(*b)) ==> (\result == \old(*a)); // If *a >= *b, result is *a

*/
int max_ptr(int *a, int *b)
{
    return (*a < *b) ? *b : *a;
}

/*@
  ensures \result == 0; // Ensure main17 returns 0
*/
int main17() {
    int h = 42; // Initialize h to 42
    int a = 24;
    int b = 42;

    int x = max_ptr(&a, &b);

    //@ assert x == 42; // Assert that x is 42
    //@ assert h == 42; // Assert that h is 42
    return 0;
}
