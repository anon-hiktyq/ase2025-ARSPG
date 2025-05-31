
int unknown1();
int unknown2();
int unknown3();

void foo(int k)
{
  int z = k;
  int x = 0;
  int y = 0;

  /*@
    loop invariant ((y == 0)&&(x == 0)&&(z == \at(k, Pre))&&(k == \at(k, Pre))) || (z >= k + y);
    loop invariant ((y == 0)&&(x == 0)&&(z == \at(k, Pre))&&(k == \at(k, Pre))) || (x == y);
    loop invariant ((y == 0)&&(x == 0)&&(z == \at(k, Pre))&&(k == \at(k, Pre))) || (x == y);
    loop invariant k == \at(k, Pre);
  */
  while(unknown1())
  {
    int c = 0;
    
    /*@
      loop invariant k == \at(k, Pre);
      loop invariant k + y <= z <= k + y + c; // Modified invariant
      loop invariant x - y <= c; // Modified invariant
      loop invariant c >= 0;
      loop invariant x >= y; // Modified invariant
    */
    while(unknown2())
    {
      if(z == k + y - c)
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
      loop invariant k + y <= z <= k + y + c; // Modified invariant
      loop invariant x - y <= c; // Modified invariant
      loop invariant c >= 0;
      loop invariant x >= y; // Modified invariant
    */
    while(unknown3())
    {
      x--;
      y--;
    }
            
    z = k + y;
  }
  
  /*@ assert x == y; */
}
