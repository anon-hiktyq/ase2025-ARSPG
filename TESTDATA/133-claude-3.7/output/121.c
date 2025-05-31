
void foo() {
 
    int i = 1;
    int sn = 0;
    
     
    
            
            /*@
          loop invariant  ((sn == 0)&&(i == 1)) || (2 <= i <= 9) ;
          loop invariant  ((sn == 0)&&(i == 1)) || (sn == i - 1 && 1 <= sn <= 8) ;
            */
            while (i <= 8) {
  
      i  = (i + 1);
      sn  = (sn + 1);
      
    }
            
  
    /*@ assert (sn != 0) ==> (sn == 8);*/
  
  }
