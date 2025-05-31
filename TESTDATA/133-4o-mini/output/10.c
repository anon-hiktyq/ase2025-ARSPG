
int unknown();
/*@ requires x >= 0 && x <= 2 && y <= 2 && y >= 0; */
void foo(int x,int y) {

    /*@      loop invariant  (0 <= x <= 4) && (0 <= y <= 4) ==> (x + 2 * (y - \at(y, Pre)) <= 6); 
    */
    while (unknown()) {
        x  = x + 2;
        y  = y + 2;
    }

    /*@ assert (y == 0) ==> (x != 4);  */
}
