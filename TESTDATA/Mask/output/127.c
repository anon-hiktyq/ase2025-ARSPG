
void foo(int x, int y, int z1, int z2, int z3) {

    int i = x;
    int j = y;
    
                
                /*@
          loop invariant (\at(x, Pre) != 0) ==> (x <= \at(x, Pre)); 
          loop invariant (\at(x, Pre) != 0) ==> (y == \at(y, Pre) - (\at(x, Pre) - x));
          loop invariant (!(\at(x, Pre) != 0)) ==> ((j == \at(y, Pre))&&(i == \at(x, Pre))&&(z3 == \at(z3, Pre))&&(z2 == \at(z2, Pre))&&(z1 == \at(z1, Pre))&&(y == \at(y, Pre))&&(x == \at(x, Pre)));
          loop invariant j == \at(y, Pre);
          loop invariant i == \at(x, Pre);
          loop invariant z3 == \at(z3, Pre);
          loop invariant z2 == \at(z2, Pre);
          loop invariant z1 == \at(z1, Pre);
                */
                while (x != 0) {
  
      x  = x - 1;
      y  = y - 1;
  
    }
                
  
    /*@ assert (y != 0) ==> (i != j); */
  
  }
