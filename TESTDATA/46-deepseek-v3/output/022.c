
int unknown();

void foo()
{
  int x = 0;
  int y = 0;
  int z = 0;
  int k = 0;

  
            
            /*@
          loop invariant  ((k == 0)&&(z == 0)&&(y == 0)&&(x == 0)) || (x == y && y == z) ;
          loop invariant  ((k == 0)&&(z == 0)&&(y == 0)&&(x == 0)) || (k == x + y + z) ;
            */
            while(unknown())
  {
     if(k%3 == 0){
        x++;
     }
      
     y++;
     z++;
     k = x + y + z;
  }
            

  /*@ assert x == y && y == z ;*/
 
}
