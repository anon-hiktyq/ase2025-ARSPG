
int unknown();
/*@ requires x >= 0 && x <= 10 && y <= 10 && y >= 0; */
void foo(int x, int y,int z1,int z2,int z3) {/*@
      loop invariant (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) ==> (((z3 == \at(z3, Pre))&&(z2 == \at(z2, Pre))&&(z1 == \at(z1, Pre))&&(y == \at(y, Pre))&&(x == \at(x, Pre))) || ((x >= \at(x, Pre) && (x - \at(x, Pre)) % 10 == 0)));
      loop invariant (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) ==> (((z3 == \at(z3, Pre))&&(z2 == \at(z2, Pre))&&(z1 == \at(z1, Pre))&&(y == \at(y, Pre))&&(x == \at(x, Pre))) || ((y >= \at(y, Pre) && (y - \at(y, Pre)) % 10 == 0)));
      loop invariant (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) ==> ((y == 0) ==> (x != 20));
      loop invariant (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) ==> (z3 == \at(z3, Pre));
      loop invariant (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) ==> (z2 == \at(z2, Pre));
      loop invariant (\at(x, Pre) >= 0 && \at(x, Pre) <= 10 && \at(y, Pre) <= 10 && \at(y, Pre) >= 0) ==> (z1 == \at(z1, Pre));
    */
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }
    /*@ assert (y == 0) ==> (x != 20); */
}
