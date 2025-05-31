
   int unknown1();
   int unknown2();
   int unknown3();

   void foo() {
       int x = 0, y = 0;

       /*@
         loop invariant  ((y == 0) && (x == 0)) || (x >= 0 && y >= 0) ;
         loop invariant  (x < 4) || (y >= 0) ;
         loop invariant  (y <= 100 * (x + 1)) ; // since y increases by 100 for each unknown2() call
         loop invariant  (y >= 100 * x - 50); // weakened to allow for fluctuations in y with respect to x
         loop invariant  (x <= 3) || (y >= 300); // ensures y is large enough when x is large
       */
       while(unknown1()) {
           if(unknown2()) { 
               x++; 
               y += 100; 
           }
           else if (unknown3()){ 
               if (x >= 4) { 
                   x++; 
                   y++; 
               } 
               if (x < 0) {
                   y--;
               }
           }
       }
       
       /*@ assert x < 4 || y > 2; */
   }
   