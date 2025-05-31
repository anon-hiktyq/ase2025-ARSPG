
int unknown1();
int unknown2();

int main(int flag)
{
  int t = 0;
  int s = 0;
  int a = 0;
  int b = 0;

  
            
            /*@          loop invariant  ((b >= 0) && (a >= 0) && (s >= 0) && (t >= 0) && (flag == \at(flag, Pre))) || (s == (a * (a + 1) / 2));
          loop invariant  ((b >= 0) && (a >= 0) && (s >= 0) && (t >= 0) && (flag == \at(flag, Pre))) || (a >= 0);
          loop invariant  ((b >= 0) && (a >= 0) && (s >= 0) && (t >= 0) && (flag == \at(flag, Pre))) || (b >= 0);
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
    x = t - 2 * s + 2;
  }
  
  int y = 0;
  
  
            
            /* >>> LOOP INVARIANT TO FILL <<< 
       >>> PRECONDITION OF THE LOOP : (exists retval_43, \at(flag, Pre) == 0 && retval_43 == 0 && retval_43 <= INT_MAX && retval_43 > INT_MIN && (y == 0) * (x == 1) * (b == 0) * (a == 0) * (s == 0) * (t == 0) * (flag == \at(flag, Pre))) || (exists retval_43, \at(flag, Pre) != 0 && retval_43 == 0 && retval_43 <= INT_MAX && retval_43 > INT_MIN && (y == 0) * (x == 0 - 2 * 0 + 2) * (b == 0) * (a == 0) * (s == 0) * (t == 0) * (flag == \at(flag, Pre))) <<< */
    
            /*@
          loop invariant  ((y == 0)&&(x >= 1)&&(b >= 0)&&(a >= 0)&&(s >= 0)&&(t >= 0)&&(flag == \at(flag, Pre))) || (y <= x)  ;
          loop invariant x >= 1; 
          loop invariant b >= 0;
          loop invariant a >= 0;
          loop invariant s >= 0;
          loop invariant t >= 0; 
          loop invariant flag == \at(flag, Pre);
          loop invariant  ((y == 0)&&(x >= 1)&&(b >= 0)&&(a >= 0)&&(s >= 0)&&(t >= 0)&&(flag == \at(flag, Pre))) || (y <= x) ;
          loop invariant x >= 1;
          loop invariant b >= 0;
          loop invariant a >= 0;
          loop invariant s >= 0;
          loop invariant t >= 0; 
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
