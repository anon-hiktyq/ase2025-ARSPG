
int unknown();
/*@ requires x >= 0 && x <= 10 && y <= 10 && y >= 0; */
void foo(int x, int y) {
    
    /*@
      loop invariant  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) ==> (((y == \at(y, Pre))&&(x == \at(x, Pre))) || ((x - \at(x, Pre)) % 10 == 0 && x >= \at(x, Pre) && x - \at(x, Pre) == y - \at(y, Pre))) ;
      loop invariant  (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) ==> (((y == \at(y, Pre))&&(x == \at(x, Pre))) || ((y - \at(y, Pre)) % 10 == 0 && y >= \at(y, Pre) && (x == 20 ==> y != 0))) ;
    */
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }
        
    /*@ assert (x ==20) ==>  (y != 0); */
}
