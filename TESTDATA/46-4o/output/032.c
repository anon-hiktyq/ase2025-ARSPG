
void foo(int b,int j) {
  int k = 100;
  int i = j;
  int n = 0;
  
  /*@
    loop invariant  ((n == 0)&&(i == \at(j, Pre))&&(k == 100)&&(j == \at(j, Pre))&&(b == \at(b, Pre))) || 
                     ((n >= 0 && n <= 2*k) &&
                      ((b == 0 && i == \at(j, Pre) + (n+1)/2 && j == \at(j, Pre) + n/2) ||
                       (b == 1 && i == \at(j, Pre) + n/2 && j == \at(j, Pre) + (n+1)/2))) ;
    loop invariant  k == 100;
  */
  for( n = 0 ; n < 2*k ; n++ ) {
    if(b) {
      i++;
    } else {
      j++;
    }
    b = !b;
  }
  
  /*@ assert i == j;*/
}
