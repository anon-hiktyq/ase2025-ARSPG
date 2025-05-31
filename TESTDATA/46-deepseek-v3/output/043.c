
int unknown();

/*@ requires x != y;
*/
void foo(int x, int y)
{
  int i=0;
  int t=y;
   
  /*@
    loop invariant y == \at(y, LoopEntry) || y >= t;
    loop invariant t == \at(y, LoopEntry);
    loop invariant i == 0;
    loop invariant x == \at(x, LoopEntry);
   */
  while (unknown()) {
    if (x > 0)   
      y = y + x;
  }
   
  /*@ assert y >= t;*/
}
