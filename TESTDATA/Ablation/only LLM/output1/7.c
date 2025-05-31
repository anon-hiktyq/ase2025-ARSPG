
int unknown();

/*@ requires x >= 0 && x <= 10 && y <= 10 && y >= 0; */
void foo(int x, int y) {
    /*@ 
      loop invariant x - y == \at(x - y, Pre);
      loop invariant x >= 0 && y >= 0;
      loop invariant x <= 10 + 10 * n && y <= 10 + 10 * n;
      loop assigns x, y;
      loop variant 0;
    */
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }

    /*@ assert (x == 20) ==> (y != 0); */
}
