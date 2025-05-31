
int unknown();
/*@ requires 0 <= y && y <= 127; */
void foo(int y) {
    int c = 0;
    int z = 36 * y;
    
    /*@ loop invariant (0 <= c <= 36);
        loop invariant (z == 36 * \at(y, Pre) + c);
        loop invariant (0 <= \at(y, Pre) && \at(y, Pre) <= 127);
    */
    while (unknown()) {

        if (c < 36)
        {
            z  = z + 1;
            c  = c + 1;
        }
      
    }

    /*@ assert (c < 36) ==> (z < 4608); */
}
