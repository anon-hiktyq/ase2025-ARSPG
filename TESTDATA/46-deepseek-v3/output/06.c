
int unknown1();
int unknown2();

void foo()
{
  int w = 1;
  int z = 0;
  int x = 0;
  int y = 0;

  
            /*@          loop invariant  x >= 0 && y >= 0;
          loop invariant  y >= 0 && x >= 0;
            */
            while(unknown1()) {
    
            /*@
          loop invariant w % 2 == 1;
          loop invariant z >= x && z >= y;
          loop invariant x >= 0 && y >= 0;
          loop invariant y >= 0 && x >= 0;
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
