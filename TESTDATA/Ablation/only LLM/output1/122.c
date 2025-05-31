
void foo(int size, int v1, int v2, int v3) {
    int i = 1;
    int sn = 0;
    
    /*@ 
      loop invariant 0 <= i <= size + 1;
      loop invariant sn == i - 1;
    */
    while (i <= size) {
        i = (i + 1);
        sn = (sn + 1);
    }
  
    /*@ assert (sn != size) ==> (sn == 0); */
}
