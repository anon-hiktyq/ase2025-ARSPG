
int unknown();

/*@ requires n > 0; */
void foo(int n, int v1, int v2, int v3) {

    int c = 0;

    /*@ loop invariant 0 <= c;
        loop assigns c;
    */
    while (unknown()) {
        {
          if (unknown()) {
            if (c > n) {
                c = c + 1;
            }
          } else {
            if (c == n) {
                c = 1;
            }
          }
        }
    }

    /*@ assert (n <= -1) ==> (c != n); */
  
}
