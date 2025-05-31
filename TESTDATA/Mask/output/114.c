
int unknown();
void foo() {

    int sn = 0;
    int x = 0;
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant  sn == x ;
      loop invariant  x >= 0 ;
    */
    while (unknown()) {
  
      x = (x + 1);
      sn = (sn + 1);
      
    }
                
    /*@ assert (sn != x) ==> (sn == -1);*/
  
}
