
void foo() {
    int x = 10000;
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant 0 <= x <= 10000 ;
    */
    while (x > 0) {
        x = x - 1;
    }
      /*@ assert x == 0; */
}
