
int unknown();
/*@ requires x >= 0 && x % 2 == 0 && y % 2 == 0 && y >= 0; */
void foo(int x, int y) {
    /*@ 
      loop invariant x % 2 == 0 && y % 2 == 0;
      loop invariant x >= 0 && y >= 0;
      loop assigns x, y;
    */
    while (unknown()) {
      x = x + 2;
      y = y + 2;
    }
  
    /*@ assert (x == 4) ==> (y != 0); */
}
