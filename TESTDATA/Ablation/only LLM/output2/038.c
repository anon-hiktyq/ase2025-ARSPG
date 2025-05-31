
void foo(int n)
{
  int x=0;
  int y=0;
  int i=0;
  
  /*@ 
      loop invariant 0 <= i <= n;
      loop invariant x == i;
      loop invariant y == i / 2;
  */
  while(i<n) {
    i++;
    x++;
    if(i%2 == 0) y++;
  }
  
 /*@assert (i%2 == 0) ==> (x==2*y); */
}
