int unknown();

/*@ requires x != y; */
void foo(int x, int y)
{
  int i=0;
  int t=y;
   
  

  while (unknown()){
    if (x > 0)   
      y = y + x;
  }
   
  /*@ assert y >= t;*/
 
}

