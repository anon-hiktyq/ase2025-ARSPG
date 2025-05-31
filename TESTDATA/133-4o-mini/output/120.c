
void foo() {
 
    int i = 1;
    int sn = 0;
    
    /*@ 
      loop invariant  (sn == i - 1) && (1 <= i <= 9);
    */
    while (i <= 8) {
  
      i  = (i + 1);
      sn  = (sn + 1);
      
    }
            
    /*@ assert (sn != 8) ==> (sn == 0);*/
}
