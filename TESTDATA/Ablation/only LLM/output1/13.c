
int unknown();
/*@ requires x >= 0 && x <= 2 && y <= 2 && y >= 0; */
void foo(int x,int y,int z1,int z2,int z3) {
    /*@ loop invariant x >= 0 && y >= 0;
        loop invariant x % 2 == 0 && y % 2 == 0;
        loop invariant x == 2 * ((x - x0) / 2) + x0 && y == 2 * ((y - y0) / 2) + y0;
        loop assigns x, y;
    */
    while (unknown()) {
        x  = x + 2;
        y  = y + 2;
    }
    /*@ assert (x == 4) ==> (y != 0);  */
}
