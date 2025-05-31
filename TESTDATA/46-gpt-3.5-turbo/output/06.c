
int unknown1();
int unknown2();

void foo()
{
  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;

  
  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : (y == 0) * (x == 0) * (z == 0) * (w == 1) <<< */
    
          /*@
        loop invariant  (w == 1) && (x >= 0) && (y >= 0) && (z == x + y) ;
        loop invariant  (y == 0) && (x == 0) && (z == 0) && (w == 1) [INVARIANT SATISFIED] ;
          */
          
    while(unknown1()) {
  
      /* >>> LOOP INVARIANT TO FILL <<< 
         >>> PRECONDITION OF THE LOOP : exists retval_40, retval_40 != 0 && retval_40 <= INT_MAX && retval_40 > INT_MIN && (y == 0) * (x == 0) * (z == 0) * (w == 1) <<< */
    
          /*@
        loop invariant w == 1;
        loop invariant z == x + y;
        loop invariant x >= 0;
        loop invariant y >= 0;
          */
          
        while(unknown2()){
          if(w%2 == 1) x++;
          if(z%2 == 0) y++;
        }
            
        z = x + y;
        w = z + 1;
  }

   /*@ assert x == y; */
}
