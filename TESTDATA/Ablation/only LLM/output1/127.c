
void foo(int x, int y, int z1, int z2, int z3) {
    int i = x;
    int j = y;
    
    /*@ loop invariant y == j - (i - x);
        loop invariant x >= 0;
        loop variant x; */
    while (x != 0) {
        x = x - 1;
        y = y - 1;
    }
  
    /*@ assert (y != 0) ==> (i != j); */
}
