
void foo(int x, int y) {

    int i = x;
    int j = y;

            /*@
          loop invariant (x >= 0) ==> (j == \at(y, Pre) && i == \at(x, Pre) && y == \at(y, Pre) - ( \at(x, Pre) - x));
          loop invariant (x >= 0) ==> (i == \at(x, Pre) && j == \at(y, Pre));
          loop invariant (x == 0) ==> (y == \at(y, Pre) - \at(x, Pre));
            */
            while (x != 0) {
  
      x  = x - 1;
      y  = y - 1;
  
    }
            
  
    /*@ assert (i == j) ==> (y == 0); */
  
}
