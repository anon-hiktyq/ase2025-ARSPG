
int unknown1();
int unknown2();
int unknown3();

void foo() {
 int x = 0, y = 0;

 /* >>> LOOP INVARIANT TO FILL <<< 
    >>> PRECONDITION OF THE LOOP : (y == 0) * (x == 0) <<< */
 
 /*@
   loop invariant  ((y == 0)&&(x == 0)) || (x >= 0) ;
   loop invariant  ((y == 0)&&(x == 0)) || (y >= 0 && y > 2) ;
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
