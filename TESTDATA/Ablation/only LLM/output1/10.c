
int unknown();
/*@ requires x >= 0 && x <= 2 && y <= 2 && y >= 0; */
void foo(int x, int y) {
    /*@ 
        loop invariant x >= 0 && y >= 0;
        loop invariant (y - x) == \at(y - x,Pre);
        loop assigns x, y;
        loop variant 0;
    */
    while (unknown()) {
        x = x + 2;
        y = y + 2;
    }
    /*@ assert (y == 0) ==> (x != 4); */
}
