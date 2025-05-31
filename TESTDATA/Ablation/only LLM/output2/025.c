
int unknown1();
int unknown2();

void foo()
{
  int x = 0;
  int y = 0;
  int i = 0;
  int j = 0;

  /*@ 
    loop invariant x <= y;
    loop invariant i >= j;
  */
  while(unknown1())
  {
    /*@ 
      loop invariant x <= y;
      loop invariant i >= j;
    */
    while(unknown2())
    {
       if(x == y){
          i++;
       }else{
          j++;
       }
    }

    if(i >= j)
    {
       x++;
       y++;
    }
    else{
       y++;
    }
  }

  /*@ assert i >= j; */
}
