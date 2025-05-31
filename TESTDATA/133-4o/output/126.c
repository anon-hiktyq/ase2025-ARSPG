
void foo(int x, int y, int z1, int z2, int z3) {

    int i = x;
    int j = y;
    
    /*@
      loop invariant x <= i; 
      loop invariant y == j - (i - x);
      loop invariant z3 == \at(z3, Pre);
      loop invariant z2 == \at(z2, Pre);
      loop invariant z1 == \at(z1, Pre);
    */
    while (x != 0) {
        x = x - 1;
        y = y - 1;
    }
    
    /*@ assert (i == j) ==> (y == 0); */
}
