
int unknown();
/*@ requires x >= 0 && x <= 10 && y <= 10 && y >= 0; */
void foo(int x, int y, int z1, int z2, int z3) {
  
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant z3 == \at(z3, Pre);
      loop invariant z2 == \at(z2, Pre);
      loop invariant z1 == \at(z1, Pre);
    */
    while (unknown()) {
        x = x + 10;
        y = y + 10;
    }
       /*@ assert (x == 20) ==>  (y != 0); */

}
111