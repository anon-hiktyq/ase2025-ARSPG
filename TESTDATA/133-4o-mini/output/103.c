
void foo() {
    int x = 0;
    
    /*@
      loop invariant  ((x == 0)) || (0 <= x <= 100) ;
    */
    while (x < 100) {
        x  = (x + 1);
    }
    
    /*@ assert x == 100 ; */
}
