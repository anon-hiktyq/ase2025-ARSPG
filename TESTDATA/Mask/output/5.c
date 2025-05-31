
void foo(int size, int y, int z)
{
    int x = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
        loop invariant (0 < \at(size, Pre)) ==> ((x >= 0) && (x <= size));
        loop invariant (!(0 < \at(size, Pre))) ==> ((x == 0) && (z == \at(z, Pre)) && (y == \at(y, Pre)) && (size == \at(size, Pre)));
        loop invariant z == \at(z, Pre);
        loop invariant size == \at(size, Pre);
    */
    while (x < size) {
        x += 1;
        if (z <= y) {
            y = z;
        }
    }
     /*@ assert (size > 0) ==> (z >= y);  */
}


113