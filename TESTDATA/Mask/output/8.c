
int unknown();
/*@ requires x >= 0 && x <= 10 && y <= 10 && y >= 0; */
void foo(int x, int y) {
  
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant  x >= \at(x, Pre) && x <= \at(x, Pre) + 10 * (y - \at(y, Pre));
      loop invariant  y >= \at(y, Pre) && y <= \at(y, Pre) + 10 * (x - \at(x, Pre));
    */
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }
     /*@ assert (y == 0) ==>  (x != 20); */
}
