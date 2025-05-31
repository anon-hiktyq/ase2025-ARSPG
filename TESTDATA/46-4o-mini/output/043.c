
int unknown();

/*@ assert x != y; */
void foo(int x, int y)
{
  int i = 0;
  int t = y;

  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : \at(x, Pre) != \at(y, Pre) && (t == \at(y, Pre)) * (i == 0) * (y == \at(y, Pre)) * (x == \at(x, Pre)) <<< */

  /*@
    loop invariant (\at(x, Pre) != \at(y, Pre)) ==> ((t == \at(y, Pre)) && (i == 0) && (y == \at(y, Pre)) && (x == \at(x, Pre)));
    loop invariant (\at(x, Pre) != \at(y, Pre)) ==> (y >= t);
  */
  while (unknown()) {
    if (x > 0)   
      y = y + x;
  }

  /*@ assert y >= t; */
}
