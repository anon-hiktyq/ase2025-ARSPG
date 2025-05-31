
int unknown();

/*@ 
  requires x != y;
*/
void foo(int x, int y)
{
  int i=0;
  int t=y;
   
  /*@ assert x != y; */
            
  /*@
    loop invariant  (\at(x, Pre) != \at(y, Pre)) ==> (((t == \at(y, Pre))&&(i == 0)&&(y == \at(y, Pre))&&(x == \at(x, Pre))) || (y > \at(y, Pre) && x > 0)) ;
    loop invariant (\at(x, Pre) != \at(y, Pre)) ==> (t == \at(y, Pre));
    loop invariant (\at(x, Pre) != \at(y, Pre)) ==> (i == 0);
    loop invariant (\at(x, Pre) != \at(y, Pre)) ==> (x == \at(x, Pre));
  */
  while (unknown()){
    if (x > 0)   
      y = y + x;
  }
            
  /*@ assert y >= t;*/
}
