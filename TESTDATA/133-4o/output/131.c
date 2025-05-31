
void foo(int x2, int x3) {

    int d1 = 1;
    int d2 = 1;
    int d3 = 1;
    int x1 = 1;

    /* >>> LOOP INVARIANT TO FILL <<< 
       >>> PRECONDITION OF THE LOOP : (x1 == 1) * (d3 == 1) * (d2 == 1) * (d1 == 1) * (x3 == \at(x3, Pre)) * (x2 == \at(x2, Pre)) <<< */

    /*@
      loop invariant ((x1 == 1)&&(d3 == 1)&&(d2 == 1)&&(d1 == 1)&&(x3 == \at(x3, Pre))&&(x2 == \at(x2, Pre))) || (x2 >= 0);
      loop invariant ((x1 == 1)&&(d3 == 1)&&(d2 == 1)&&(d1 == 1)&&(x3 == \at(x3, Pre))&&(x2 == \at(x2, Pre))) || (x3 >= 0);
      loop invariant ((x1 == 1)&&(d3 == 1)&&(d2 == 1)&&(d1 == 1)&&(x3 == \at(x3, Pre))&&(x2 == \at(x2, Pre))) || (x1 >= 0);
      loop invariant d3 == 1;
      loop invariant d2 == 1;
      loop invariant d1 == 1;
    */
    while (x1 > 0) {
        if (x2 > 0) {
            if (x3 > 0) {
                x1 = x1 - d1;
                x2 = x2 - d2;
                x3 = x3 - d3;
            }
        }
    }

    /*@ assert x3 >= 0; */

}
