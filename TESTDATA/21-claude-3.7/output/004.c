
void foo() {
    int i,j;
    i = 1;
    j = 10;

    /*@
      loop invariant  ((j == 10)&&(i == 1)) || (i == 21-2*j) ;
      loop invariant  ((j == 10)&&(i == 1)) || (j <= 10 && j >= 6) ;
    */
    while (j >= i) {
        i = i + 2;
        j = -1 + j;
    }

    /*@ assert j == 6;*/
    
}
