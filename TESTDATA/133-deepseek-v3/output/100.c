
/*@ requires n>=0; */
void foo(int n) {

    int x = n;
    int y = 0;
    
    /*@
      loop invariant x + y == \at(n, Pre);
      loop invariant n == \at(n, Pre);
      loop invariant x >= 0;
    */
    while (x > 0) {
      y = y + 1;
      x = x - 1;
    }
  
    /*@ assert y == n ; */
}
