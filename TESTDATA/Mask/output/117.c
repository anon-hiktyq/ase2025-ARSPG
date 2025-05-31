
/*@
  requires x == 0 && sn == 0 && v3 == v3 && v2 == v2 && v1 == v1;
*/
int unknown();
void foo(int v1, int v2, int v3) {

    int sn = 0;
    int x = 0;

        /*@
          loop invariant sn == x;
          loop invariant x >= 0;
          loop invariant v3 == v3;
          loop invariant v2 == v2;
          loop invariant v1 == v1;
        */
        while (unknown()) {
  
            x = (x + 1);
            sn = (sn + 1);
      
        }
        /*@ assert (sn != -1) ==> (sn == x);*/
}
