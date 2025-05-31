
void foo(int y) {
    int x = 1;
    
    /*@
      loop invariant  (x >= 1 && x <= 11) ;
      loop invariant  (y >= 0) ;
    */
    while (x <= 10) {
        y = 10 - x;
        x = x + 1;
    }
            
    /*@ assert (y >= 0); */
}
