
    
int unknown1();
int unknown2();
int unknown3();

void foo(int k)
{
  int z = k;
  int x = 0;
  int y = 0;

 
  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : (y == 0) * (x == 0) * (z == \at(k, Pre)) * (k == \at(k, Pre)) <<< */
    
            /*@
          loop invariant  ((y == 0)&&(x == 0)&&(z == \at(k, Pre))&&(k == \at(k, Pre))) || (z == k + y);
          loop invariant  ((y == 0)&&(x == 0)&&(z == \at(k, Pre))&&(k == \at(k, Pre))) || (x >= 0);
          loop invariant  ((y == 0)&&(x == 0)&&(z == \at(k, Pre))&&(k == \at(k, Pre))) || (0 <= y && y <= k);
          loop invariant k == \at(k, Pre);
            */
            while(unknown1())
  {
    int c = 0;
    
            
            /*@
          loop invariant 0 <= x <= k + y + c; 
          loop invariant 0 <= y <= k + c; 
          loop invariant c >= 0; 
          loop invariant z == k + y; 
          loop invariant c == 0 -> y == 0; 
            */
            while(unknown2())
    {
      if(z==k+y-c)
      {
        x++;
        y++;
        c++;
      }else
      {
        x++;
        y--;
        c++;
      }
    }
            

    
            
            /* >>> LOOP INVARIANT TO FILL <<< 
               >>> PRECONDITION OF THE LOOP : (y == 0) * (x == 0) * (z == \at(k, Pre)) * (k == \at(k, Pre)) <<< */
    
            /*@
          loop invariant x + y + c == k;
          loop invariant z == k + y;
          loop invariant x >= 0;
          loop invariant 0 <= y && y <= k;
          loop invariant c >= 0;
            */
            while(unknown3())
    {
      x--;
      y--;
    }
            
    z=k+y;
  }
            

  /*@ assert x==y; */
}
