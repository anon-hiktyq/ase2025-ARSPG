
int unknown();
/*@ requires x >= y  && y >= 0; */
void foo(int x, int y,int z1,int z2,int z3) {

    int i = 0;
    
    
    
            
            /*@
          loop invariant  (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (((i == 0)&&(z3 == \at(z3, Pre))&&(z2 == \at(z2, Pre))&&(z1 == \at(z1, Pre))&&(y == \at(y, Pre))&&(x == \at(x, Pre))) || ((i >= 1 && i <= y))) ;
          loop invariant (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (z3 == \at(z3, Pre));
          loop invariant (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (z2 == \at(z2, Pre));
          loop invariant (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (z1 == \at(z1, Pre));
          loop invariant (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (y == \at(y, Pre));
          loop invariant (\at(x, Pre) >= \at(y, Pre) && \at(y, Pre) >= 0) ==> (x == \at(x, Pre));
            */
            while (unknown()) {
      if ( i < y )
      {
      i  = (i + 1);
      }

    }
            

    /*@ assert (i < 0 && i >= x) ==> (i >= y); */

}
