
int unknown();
/*@ requires x >= 0 && x <= 10 && y <= 10 && y >= 0; */
void foo(int x, int y, int z1, int z2, int z3) {
    /*@ 
        loop invariant x >= 0;
        loop invariant y >= 0;
        loop invariant x - y == \at(x - y, Pre);
        loop assigns x, y;
    */
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }
    /*@ assert (x == 20) ==> (y != 0); */
}
