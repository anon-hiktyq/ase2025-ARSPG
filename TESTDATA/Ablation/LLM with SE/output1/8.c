
int unknown();
/*@ requires x >= 0 && x <= 10 && y <= 10 && y >= 0; */
void foo(int x, int y) {
  
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
        loop invariant  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) ==> (((y == \at(y, Pre))&&(x == \at(x, Pre))) || (x == \at(x, Pre) + 10 * (\at(y, Pre) - y) / 10)) ;
        loop invariant  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) ==> (((y == \at(y, Pre))&&(x == \at(x, Pre))) || (y == \at(y, Pre) + 10 * (\at(x, Pre) - x) / 10)) ;
    */
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }

    /*@ assert (y == 0) ==>  (x != 20); */
}
