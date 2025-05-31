
void foo(int y, int z1, int z2, int z3) {

    int x = 1;
    
                /*@
          loop invariant (!(1 < \at(y, Pre))) ==> ((x == 1) && (z3 == \at(z3, Pre)) && (z2 == \at(z2, Pre)) && (z1 == \at(z1, Pre)) && (y == \at(y, Pre)));
          loop invariant z3 == \at(z3, Pre);
          loop invariant z2 == \at(z2, Pre);
          loop invariant z1 == \at(z1, Pre);
          loop invariant y == \at(y, Pre);
                */
                while (x < y) {
  
       x  = x + x;
       
    }
                
  
    /*@ assert x >= 1;*/
  
}
-1