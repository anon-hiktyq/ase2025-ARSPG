
void foo() {
 
    int i = 1;
    int sn = 0;
    
    /*@
      loop invariant  ((sn == 0)&&(i == 1)) || (sn == i - 1) ;
      loop invariant  ((sn == 0)&&(i == 1)) || (sn == i - 1) ;
      loop invariant i <= 9;
    */
    while (i <= 8) {
  
      i  = (i + 1);
      sn  = (sn + 1);
      
    }
            
    /*@ assert (sn != 8) ==> (sn == 0);*/
  
}
