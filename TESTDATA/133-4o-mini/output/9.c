
int unknown();
/*@ requires x >= 0 && x <= 2 && y <= 2 && y >= 0; */
void foo(int x,int y) {
    
    /*@      loop invariant  (\at(x, Pre) >= 0 && \at(x, Pre) <= 2 && \at(y, Pre) <= 2 && \at(y, Pre) >= 0) ==> (x + y <= 4) && (x <= 4) && (y <= 4);
    */
    while (unknown()) {
        x  = x + 2;
        y  = y + 2;
    }

    /*@ assert (x == 4) ==> (y != 0);  */
}
