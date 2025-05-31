
int unknown();
/*@ requires x >= 0 && x <= 10 && y <= 10 && y >= 0; */
void foo(int x, int y) {
  
    /*@      loop invariant (x == \at(x, Pre) + 10 * ((x - \at(x, Pre)) / 10)) ;
      loop invariant (y == \at(y, Pre) + 10 * ((x - \at(x, Pre)) / 10)) ;
    */
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }

    /*@ assert (x ==20) ==>  (y != 0); */
}
