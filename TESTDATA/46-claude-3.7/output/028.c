
int unknown();

void foo() {
  int x = 0;
  int y = 0;
  int n = 0;
 
  
            
            /*@
          loop invariant  ((n == 0)&&(y == 0)&&(x == 0)) || ((x > 0) && (x == y)) ;
          loop invariant  ((n == 0)&&(y == 0)&&(x == 0)) || ((y > 0) && (x == y)) ;
          loop invariant n == 0;
            */
            while(unknown()) {
      x++;
      y++;
  }
            
 
  
            
            /*@
          loop invariant  ((n == 0)&&(y == 0)&&(x == 0)) || ((x > n) && (x == y)) ;
          loop invariant  ((n == 0)&&(y == 0)&&(x == 0)) || ((y > n) && (x == y)) ;
          loop invariant n == 0;
            */
            while(x!=n) {
      x--;
      y--;
  }
            
  /*@ assert y == n; */
}
