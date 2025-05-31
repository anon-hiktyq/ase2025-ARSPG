
int unknown();
void foo() {

    int sn = 0;
    int x = 0;
    
            /*@
          loop invariant  ((x == 0)&&(sn == 0)) || (sn >= 0 && x >= 0 && sn == x) ;
          loop invariant  ((x == 0)&&(sn == 0)) || (x >= 0 && sn >= 0) ;
            */
            while (unknown()) {
  
      x  = (x + 1);
      sn  = (sn + 1);
      
    }
            
    /*@ assert (sn != x) ==> (sn == -1);*/
  
}
