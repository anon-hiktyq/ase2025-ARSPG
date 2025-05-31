
void foo() {
    int x = 10000;
    
    /*@
    loop invariant ((x == 10000)) || (0 <= x && x < 10000);
    */
    while (x > 0) {
      x = x - 1;
    }
            
    /*@ assert x == 0; */
}
