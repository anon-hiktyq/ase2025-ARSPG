
int unknown1();
int unknown2();

void foo()
{
  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;

  
                
                /*@
          loop invariant  ((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (w == z + 1) ;
          loop invariant  ((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (z == x + y) ;
          loop invariant  ((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (x >= 0) ;
          loop invariant  ((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (y >= 0) ;
                */
                while(unknown1()) {
	  
    
                
                /*@
                loop invariant x >= 0;
                loop invariant y >= 0;
                loop invariant w == z + 1; // Added to ensure x == y holds
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
