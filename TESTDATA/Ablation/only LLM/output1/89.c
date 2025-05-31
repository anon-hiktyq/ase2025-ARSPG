
int unknown();

int main(int y,int v1,int v2,int v3) {

    int lock = 1;
    int x = y;

    /*@ 
      loop invariant x == y && lock == 1;
      loop assigns x, y, lock;
      loop variant 0;
    */
    while (x != y) {
        if (unknown()) {
          
          lock = 1;
          x = y;
          
        } else {
          
          lock = 0;
          x = y;
          y = y + 1;
          
        }
    }
    /*@ assert lock == 1;*/
}
