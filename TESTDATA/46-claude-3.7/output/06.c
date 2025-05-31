
int unknown1();
int unknown2();

void foo()
{
  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;

  
  
            
            /*@
          loop invariant  ((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (w == 2*x + 1 && w % 2 == 1) ;
          loop invariant  ((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (z == 2*x && z % 2 == 0) ;
          loop invariant  ((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (x >= 0 && x == y) ;
          loop invariant  ((y == 0)&&(x == 0)&&(z == 0)&&(w == 1)) || (y >= 0 && y == x) ;
            */
            while(unknown1()) {
	  
    
            
            /*@
          loop invariant w % 2 == 1;
          loop invariant z % 2 == 0;
          loop invariant x == y;
          loop invariant x >= 0 && y >= 0;
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
