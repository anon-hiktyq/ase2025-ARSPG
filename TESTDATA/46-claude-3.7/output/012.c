
int unknown1();
int unknown2();


int main(int flag)
{
  int t = 0;
  int s = 0;
  int a = 0;
  int b = 0;

  
            
            /*@
          loop invariant  ((b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == \at(flag, Pre))) || ((!flag && t == s) || (flag && t == 2*s)) ;
          loop invariant  ((b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == \at(flag, Pre))) || (s == (a*(a+1))/2) ;
          loop invariant  ((b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == \at(flag, Pre))) || (a >= 1) ;
          loop invariant  ((b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == \at(flag, Pre))) || (b >= 1 && b == a) ;
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
          loop invariant  ((y == 0)&&(x == 0 - 2 * 0 + 2)&&(b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == \at(flag, Pre))) || (0 <= y <= 4) ;
          loop invariant (flag != 0 && x == 2) || (flag == 0 && x == 1);
          loop invariant b == a;
          loop invariant a == 0 || a >= 1;
          loop invariant s == 0 || s == (a*(a+1))/2;
          loop invariant t == 0 || ((!flag && t == s) || (flag && t == 2*s));
          loop invariant flag == \at(flag, Pre);
          loop invariant  ((y == 0)&&(x == 1)&&(b == 0)&&(a == 0)&&(s == 0)&&(t == 0)&&(flag == \at(flag, Pre))) || (0 <= y <= 4) ;
          loop invariant (flag != 0 && x == 2) || (flag == 0 && x == 1);
          loop invariant b == a;
          loop invariant a == 0 || a >= 1;
          loop invariant s == 0 || s == (a*(a+1))/2;
          loop invariant t == 0 || ((!flag && t == s) || (flag && t == 2*s));
          loop invariant flag == \at(flag, Pre);
            */
            while(y <= x){
    if(unknown2()) 
       y++;
    else 
       y += 2;
  }
            
  /*@ assert y <= 4; */
}
