
int unknown1();
int unknown2();

void foo()
{
  int x = 0;
  int y = 0;
  int i = 0;
  int j = 0;

  /* >>> LOOP INVARIANT TO FILL <<< */
  /*@
    loop invariant ((j == 0)&&(i == 0)&&(y == 0)&&(x == 0)) || (0 <= x);
    loop invariant ((j == 0)&&(i == 0)&&(y == 0)&&(x == 0)) || (0 <= y);
    loop invariant ((j == 0)&&(i == 0)&&(y == 0)&&(x == 0)) || (i >= j);
    loop invariant ((j == 0)&&(i == 0)&&(y == 0)&&(x == 0)) || (x <= y);
  */
  while(unknown1())
  {
    /*@
      loop invariant 0 <= x;
      loop invariant 0 <= y;
      loop invariant i >= j;
      loop invariant x <= y;
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
