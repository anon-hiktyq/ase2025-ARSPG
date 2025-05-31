
   void foo(int x, int y) {

       int i = x;
       int j = y;
       
           /*@
           loop invariant (i == \at(x, Pre) && j == \at(y, Pre));
           loop invariant (x >= 0) ==> (i == \at(x, Pre) && j == \at(y, Pre));
           loop invariant (x >= 0) ==> (y == \at(y, Pre) - (\at(x, Pre) - x));
           */
           while (x != 0) {
   
         x  = x - 1;
         y  = y - 1;
   
       }
               
       /*@ assert (y != 0) ==> (i != j); */
   
   }
   