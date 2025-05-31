
int unknown1();
int unknown2();

int main(int flag)
{
  int t = 0;
  int s = 0;
  int a = 0;
  int b = 0;

  /*@
    loop invariant a == b;
    loop invariant s == a * (a + 1) / 2;
    loop invariant t == b * (b + 1) / 2 + (flag ? a * (a + 1) / 2 : 0);
    loop invariant a >= 0;
    loop invariant b >= 0;
    loop invariant s >= 0;
    loop invariant t >= 0;
  */
  while(unknown1()) {
    a++;
    b++;
    s += a;
    t += b;
    if(flag) {
      t += a;
    }
  }
  
  int x = 1;

  if(flag) {
    x = t - 2 * s + 2;
  }
  
  int y = 0;
  
  /*@
    loop invariant y <= x + 2;
    loop invariant x <= 2;
  */
  while(y <= x){
    if(unknown2()) 
       y++;
    else 
       y += 2;
  }
                
  /*@ assert y <= 4; */
}
