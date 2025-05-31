
void foo(int y) {

    int x = 1;
    
    /*@
      loop invariant (1 < \at(y, Pre)) ==> (((x == 1)&&(y == \at(y, Pre))) || (x >= 1));
      loop invariant (!(1 < \at(y, Pre))) ==> ((x == 1)&&(y == \at(y, Pre)));
      loop invariant y == \at(y, Pre);
    */
    while (x < y) {
  
       x  = x + x ;
       
    }
            
    /*@ assert x >= 1;*/
  
}
