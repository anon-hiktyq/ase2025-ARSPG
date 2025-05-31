
void foo() {

    int x = 0;
    int y = 0;

    /*@
      loop invariant  ((y == 0)&&(x == 0)) || (y >= 0) ;
      loop invariant x == 0;
    */
    while(y >= 0) {
        y = y + x;
    }
    
    /*@ assert y >= 0;*/

}
