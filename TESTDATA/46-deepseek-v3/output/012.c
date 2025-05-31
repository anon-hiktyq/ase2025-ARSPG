
int unknown1();
int unknown2();

int main(int flag)
{
  int t = 0;
  int s = 0;
  int a = 0;
  int b = 0;

  /*@
    loop invariant  ((b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == \at(flag, Pre))) || (t == (flag ? 2*s : s)) ;
    loop invariant  ((b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == \at(flag, Pre))) || (s == a*(a+1)/2) ;
    loop invariant  ((b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == \at(flag, Pre))) || (a == b) ;
    loop invariant  ((b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == \at(flag, Pre))) || (b == a) ;
    loop invariant flag == \at(flag, Pre);
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
    x = t - 2*s + 2;
  }
  
  int y = 0;
  
  /*@
    loop invariant (flag == 0 ==> x == 1) && (flag != 0 ==> x == t - 2*s + 2);
    loop invariant b == a;
    loop invariant s == a*(a+1)/2;
    loop invariant t == (flag ? 2*s : s);
    loop invariant flag == \at(flag, Pre);
    loop invariant y <= x + 2;
  */
  while(y <= x){
    if(unknown2()) 
       y++;
    else 
       y += 2;
  }
  
  /*@ assert y <= 4; */
}
