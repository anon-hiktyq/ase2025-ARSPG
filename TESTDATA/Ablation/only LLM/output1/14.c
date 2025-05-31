
int unknown();

/*@ requires x >= 0 && x <= 2 && y <= 2 && y >= 0; */
void foo(int x,int y,int z1,int z2,int z3) {
    /*@ 
        loop invariant x >= 0 && x <= 2 + 2 * (x / 2) && 
                        y >= 0 && y <= 2 + 2 * (y / 2);
        loop assigns x, y;
        loop variant (x + y) / 2; 
    */
    while (unknown()) {
        x = x + 2;
        y = y + 2;
    }
    /*@ assert (y == 0) ==> (x != 4);  */
}
