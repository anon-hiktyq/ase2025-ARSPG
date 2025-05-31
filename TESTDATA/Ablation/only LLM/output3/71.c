
int unknown();
/*@ requires 0 <= y && y <= 127; */
void foo(int y) {
    int c = 0;
    int z = 36 * y;
    
    /*@ 
        loop invariant 0 <= c <= 36;
        loop invariant z == 36 * y + c;
        loop invariant 0 <= y <= 127;
        loop assigns z, c;
        loop variant 36 - c;
    */
    while (unknown()) {
        if (c < 36) {
            z = z + 1;
            c = c + 1;
        }
    }
    
}
