
int unknown();
/*@ requires 0 <= y && y <= 127; */
void foo(int y) {
    int c = 0;
    int z = 36 * y;
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant  z == 36 * \at(y, Pre) + c ;
      loop invariant  c <= 36 ;
      loop invariant y == \at(y, Pre);
    */
    while (unknown()) {
        if (c < 36) {
            z = z + 1;
            c = c + 1;
        }
    }
}
