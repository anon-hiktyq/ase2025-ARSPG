
int unknown1();
int unknown2();

void foo()
{
  int x = 0;
  int y = 0;
  int i = 0;
  int j = 0;

  /*@
    loop invariant x == y ;
    loop invariant x >= 0 ;
    loop invariant y >= 0 ;
    loop invariant i >= j ;
    loop invariant i >= 0 ;
    loop invariant j >= 0 ;
  */
  while(unknown1())
  {
    /*@
      loop invariant x == y ;
      loop invariant x >= 0 ;
      loop invariant y >= 0 ;
      loop invariant i >= j ;
      loop invariant i >= 0 ;
      loop invariant j >= 0 ;
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
