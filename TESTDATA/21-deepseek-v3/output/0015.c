
/*@
requires y <= 1000000;
*/
void foo(int x, int y) {
    if (y > 0) {
        /*@
          loop invariant (\at(y, Pre) > 0 && \at(y, Pre) <= 1000000) ==> ((!(\at(x, Pre) < 100)) ==> ((y == \at(y, Pre))&&(x == \at(x, Pre))));
          loop invariant (\at(y, Pre) > 0 && \at(y, Pre) <= 1000000) ==> (y == \at(y, Pre));
        */
        while (x < 100) {
            x = x + y;
        }
    }
    //@ assert y <= 0 || (y > 0 && x >= 100);
}
