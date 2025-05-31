
void foo() {
  
    int i=1;
    int j=20;
   
    /*@
      loop invariant  ((j == 20)&&(i == 1)) || ((i >= 1) && (i % 2 == 1)) ;
      loop invariant  ((j == 20)&&(i == 1)) || ((j <= 20) && (i + 2*j == 41)) ;
      loop invariant  j < i ==> j == 13;
    */
    while (j >= i) {
      
      i  = i + 2;
      j  = j - 1;
      
  
    }
            
  
    /*@ assert j == 13;*/
  
}
