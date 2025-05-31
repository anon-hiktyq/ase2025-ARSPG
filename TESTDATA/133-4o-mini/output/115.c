
int unknown();
void foo() {

    int sn = 0;
    int x = 0;
    
            /*@
          loop invariant  ((x == 0)&&(sn == 0)) || (sn == x) ;
          loop invariant  ((x == 0)&&(sn == 0)) || (0 <= x && 0 <= sn) ;
            */
            while (unknown()) {
  
      x  = (x + 1);
      sn  = (sn + 1);
      
    }
            
       /*@ assert (sn != -1) ==> (sn == x);*/
}
