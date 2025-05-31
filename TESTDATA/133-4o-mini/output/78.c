
int unknown();
/*@ requires x >= y  && y >= 0; */
void foo(int x, int y) {

    int i = 0;
    
    /*@ 
      loop invariant (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (i >= 0);
      loop invariant (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (i <= \at(y, Pre));
      loop invariant (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (y == \at(y, Pre));
      loop invariant (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (x == \at(x, Pre));
    */
    while (unknown()) {
        if (i < y) {
            i = (i + 1);
        }
    }
    
    /*@ assert (i < y) ==> (i >= 0); */
}
