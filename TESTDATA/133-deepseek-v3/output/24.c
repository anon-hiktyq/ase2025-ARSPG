
void foo() {
    int i=1;
    int j=10;
    
    /*@
      loop invariant (j == 10 && i == 1) || (i + 2*j == 21);
      loop invariant 10 - j == (i - 1)/2;
      loop invariant 1 <= i <= 9;
      loop invariant 6 <= j <= 10;
    */
    while (j >= i) {
        i = i + 2;
        j = j - 1;
    }
    
    /*@ assert j == 6;*/
}
