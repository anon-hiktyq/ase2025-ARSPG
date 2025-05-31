
void foo(int b,int j) {
  int k = 100;
  int i = j;
  int n = 0;
  
            
            /*@
          loop invariant  ((n == 0)&&(i == \at(j, Pre))&&(k == 100)&&(j == \at(j, Pre))&&(b == \at(b, Pre))) || (n <= 2*k) ;
          loop invariant  ((n == 0)&&(i == \at(j, Pre))&&(k == 100)&&(j == \at(j, Pre))&&(b == \at(b, Pre))) || (i <= j + n) ; 
          loop invariant  ((n == 0)&&(i == \at(j, Pre))&&(k == 100)&&(j == \at(j, Pre))&&(b == \at(b, Pre))) || (i - j == n) ;
          loop invariant  ((n == 0)&&(i == \at(j, Pre))&&(k == 100)&&(j == \at(j, Pre))&&(b == \at(b, Pre))) || (n <= 2*k) ;
          loop invariant k == 100;
            */
            for( n = 0 ; n < 2*k ; n++ ) {
    if(b) {
      i++;
    } else {
      j++;
    }
    b = !b;
  }
            
  /*@ assert i == j; */
}
