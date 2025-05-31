
void foo() {
    int x = 100;
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant  x >= 0 && x <= 100 ;
    */
    while (x > 0) {
        x = x - 1;
    }
    /*@ assert x == 0; */
}
