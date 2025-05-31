
void foo() {
  
    int i=1;
    int j=20;

    /*@
      loop invariant  (j >= 13) && (i == 2 * (20 - j) + 1);
      loop invariant  (j == 20) || (j >= 13);
    */
    while (j >= i) {
      
      i  = i + 2;
      j  = j - 1;
  
    }
            
    /*@ assert j == 13; */
}
