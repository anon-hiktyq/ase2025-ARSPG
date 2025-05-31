
void foo() {
  
    int i=1;
    int j=10;
   
    /*@
        loop invariant  (i >= 1);
        loop invariant  (j == 10 - (i - 1)/2);
        loop invariant  (j + i >= 6 && j + i <= 11); // Adjusted range constraint
    */
    while (j >= i) {
        i  = i + 2;
        j  = j - 1;
    }
  
    /*@ assert j == 6;*/
}
