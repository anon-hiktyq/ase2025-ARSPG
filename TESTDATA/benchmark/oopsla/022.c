int unknown();

void foo()
{
  int x = 0;
  int y = 0;
  int z = 0;
  int k = 0;

  while(unknown())
  {
     if(k%3 == 0){
        x++;
     }
      
     y++;
     z++;
     k = x+y+z;
  }

  /*@ assert x == y && y == z ;*/
 
}
