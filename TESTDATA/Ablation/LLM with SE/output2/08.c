
int unknown1();
int unknown2();
int unknown3();

void foo() {
 int x = 0, y = 0;

 /* >>> LOOP INVARIANT TO FILL <<< */
        
 /*@
   loop invariant  ((y == 0)&&(x == 0)) || (x >= 0 && y == 100 * x) ;
   loop invariant  ((y == 0)&&(x == 0)) || (x < 4 && y >= x) ;
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
