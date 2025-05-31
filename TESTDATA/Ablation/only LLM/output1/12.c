
int unknown();

/*@ requires x >= 0 && x <= 10 && y <= 10 && y >= 0; */
void foo(int x, int y, int z1, int z2, int z3) {
    /*@ loop invariant x >= 0 && x <= 10 + 10 * \count;
        loop invariant y >= 0 && y <= 10 + 10 * \count;
    */
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }

    /*@ assert (y == 0) ==> (x != 20); */
}
