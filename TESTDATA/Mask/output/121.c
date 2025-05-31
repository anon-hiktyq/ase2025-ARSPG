
void foo() {
    int i = 1;
    int sn = 0;
    
    /*@
      loop invariant  1 <= i <= 9 ; // Modified invariant to ensure preservation
      loop invariant  sn == i - 1 ;
    */
    while (i <= 8) {
        i = (i + 1);
        sn = (sn + 1);
    }
      /*@ assert (sn != 0) ==> (sn == 8);*/
}
