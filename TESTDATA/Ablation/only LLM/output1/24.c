
void foo() {
    int i = 1;
    int j = 10;
    
    /*@ 
      loop invariant 0 <= i <= j + 1;
      loop invariant j >= 6;
      loop assigns i, j;
    */
    while (j >= i) {
        i = i + 2;
        j = j - 1;
    }
  
    /*@ assert j == 6; */
}
