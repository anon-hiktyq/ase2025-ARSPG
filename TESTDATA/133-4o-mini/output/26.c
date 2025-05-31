
void foo(int n) {
    int x = n;
    
    /*@
      loop invariant (\at(n, Pre) > 1) ==> ((x == \at(n, Pre) - (n - x)) && (x > 0));
      loop invariant (!(\at(n, Pre) > 1)) ==> (x == \at(n, Pre));
      loop invariant n == \at(n, Pre);
    */
    while (x > 1) {
        x = x - 1;
    }
    
    /*@ assert (x != 1) ==> (n < 1); */
}
