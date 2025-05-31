
void foo() {

    int x = 0 ;
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant  0 <= x <= 100 ;
      loop invariant  x == 0 + (x - 0) ;
    */
    while (x < 100) {
      
      x = (x + 1);
  
    }
                
   /*@ assert x == 100 ;*/
}
