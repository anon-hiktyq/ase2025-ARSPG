
void foo(int y,int z1,int z2,int z3) {
    int x = -50;

            /*@          loop invariant (z3 == \at(z3, Pre)) && (z2 == \at(z2, Pre)) && (z1 == \at(z1, Pre)) && (y == \at(y, Pre)) || (y >= -50) ;
          loop invariant (x < 0) && (y >= -50);
            */
            while (x < 0) {
                x  = x + y;
                y  = y + 1;
            }

            /*@ assert y > 0; */
}
