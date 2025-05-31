
void foo(int z1,int z2,int z3) {

    int x = 0;
    int y = 0;

    
            
    /* >>> LOOP INVARIANT TO FILL <<< 
       >>> PRECONDITION OF THE LOOP : (y == 0) * (x == 0) * (z3 == \at(z3, Pre)) * (z2 == \at(z2, Pre)) * (z1 == \at(z1, Pre)) <<< */

            /*@
          loop invariant  ((y == 0)&&(x == 0)&&(z3 == \at(z3, Pre))&&(z2 == \at(z2, Pre))&&(z1 == \at(z1, Pre))) || (y >= 0) ;
          loop invariant x == 0;
          loop invariant z3 == \at(z3, Pre);
          loop invariant z2 == \at(z2, Pre);
          loop invariant z1 == \at(z1, Pre);
            */
            while(y >= 0) {
        y = y + x;
    }
            
    /*@ assert y >= 0;*/

}
