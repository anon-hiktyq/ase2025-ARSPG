
int unknown();
/*@ requires x >= y  && y >= 0; */
void foo(int x, int y, int z1, int z2, int z3) {
    int i = 0;
    
    /*@ 
      loop invariant 0 <= i <= y;
      loop assigns i;
    */
    while (unknown()) {
        if (i < y) {
            i = (i + 1);
        }
    }

    /*@ assert (i < 0 && i >= x) ==> (i >= y); */
}
