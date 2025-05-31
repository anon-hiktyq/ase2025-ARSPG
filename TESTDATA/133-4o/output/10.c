
int unknown();
/*@ requires x >= 0 && x <= 2 && y <= 2 && y >= 0; */
void foo(int x, int y) {

    /*@
      loop invariant  (x >= \at(x, Pre)) && (y >= \at(y, Pre));
      loop invariant  (x - y == \at(x, Pre) - \at(y, Pre));
      loop invariant  (x <= 2 * (\at(x, Pre) + y)) && (y <= 2 * (\at(y, Pre) + x));
     */
    while (unknown()) {

        x = x + 2;
        y = y + 2;

    }

    /*@ assert (y == 0) ==> (x != 4); */
}
