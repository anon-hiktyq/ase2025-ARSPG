
int unknown1();
int unknown2();
int unknown3();

void foo(int k)
{
  int z = k;
  int x = 0;
  int y = 0;

  
            /*@          loop invariant k == \at(k, Pre);
            */
            while(unknown1())
  {
    int c = 0;
    
            
            /*@
          loop invariant k == \at(k, Pre);
          loop invariant z == k + y - c;
          loop invariant x == y + c;
          loop invariant c >= 0;
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
            

    
            
            /*@
          loop invariant k == \at(k, Pre);
          loop invariant z == k + y;
          loop invariant x == y + \at(c, LoopEntry);
          loop invariant \at(c, LoopEntry) >= 0;
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
