
void foo(int y, int z1, int z2, int z3) {
    int x = 1;
    
    /*@ 
      loop invariant x >= 1;
      loop invariant x <= \pow(2, \loop_iteration) * x;
      loop invariant x < y ==> \loop_iteration < (y - x);
      loop assigns x;
      loop variant y - x;
    */
    while (x < y) {
        x = x + x;
    }
}
