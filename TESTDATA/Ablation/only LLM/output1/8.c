
int unknown();
/*@ requires x >= 0 && x <= 10 && y <= 10 && y >= 0; */
void foo(int x, int y) {
    /*@ 
      loop invariant x >= 0 && x <= 10 + 10 * \at(k, Pre);
      loop invariant y >= 0 && y <= 10 + 10 * \at(k, Pre);
      loop invariant k >= 0;
    */
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }
    /*@ assert (y == 0) ==> (x != 20); */
}
