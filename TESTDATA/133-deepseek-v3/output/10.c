
int unknown();
/*@ requires x >= 0 && x <= 2 && y <= 2 && y >= 0; */
void foo(int x,int y) {

    /*@
      loop invariant x >= \at(x, Pre) && x <= \at(x, Pre) + 2*(\at(x, LoopCurrent) - \at(x, Pre))/2;
      loop invariant y >= \at(y, Pre) && y <= \at(y, Pre) + 2*(\at(y, LoopCurrent) - \at(y, Pre))/2;
      loop invariant x - \at(x, Pre) == y - \at(y, Pre);
      loop invariant y == 0 ==> x == \at(x, Pre);
    */
    while (unknown()) {
        x = x + 2;
        y = y + 2;
    }
            
    /*@ assert (y == 0) ==> (x != 4); */
}
