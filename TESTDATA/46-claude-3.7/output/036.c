
int unknown1();
int unknown2();
int unknown3();

void foo(int flag) {
  int a = 0;
  int b = 0;
  int x = 0;
  int y = 0;
  int z = 0;
  int j = 0;
  int w = 0;

 
  
            
    /* >>> LOOP INVARIANT TO FILL <<< 
       >>> PRECONDITION OF THE LOOP : (w == 0) * (j == 0) * (z == 0) * (y == 0) * (x == 0) * (b == 0) * (a == 0) * (flag == \at(flag, Pre)) <<< */
    
            /*@
          loop invariant  ((w == 0)&&(j == 0)&&(z == 0)&&(y == 0)&&(x == 0)&&(b == 0)&&(a == 0)&&(flag == \at(flag, Pre))) || (x >= 0) ;
          loop invariant  ((w == 0)&&(j == 0)&&(z == 0)&&(y == 0)&&(x == 0)&&(b == 0)&&(a == 0)&&(flag == \at(flag, Pre))) || (y >= 0) ;
          loop invariant  ((w == 0)&&(j == 0)&&(z == 0)&&(y == 0)&&(x == 0)&&(b == 0)&&(a == 0)&&(flag == \at(flag, Pre))) || (z > 0) ;
          loop invariant  ((w == 0)&&(j == 0)&&(z == 0)&&(y == 0)&&(x == 0)&&(b == 0)&&(a == 0)&&(flag == \at(flag, Pre))) || (j >= 0) ;
          loop invariant  ((w == 0)&&(j == 0)&&(z == 0)&&(y == 0)&&(x == 0)&&(b == 0)&&(a == 0)&&(flag == \at(flag, Pre))) || (w >= z) ;
          loop invariant b == 0;
          loop invariant a == 0;
          loop invariant flag == \at(flag, Pre);
            */
            while (unknown1()) {
    int i = z;
    int j = w;
    int k = 0;
