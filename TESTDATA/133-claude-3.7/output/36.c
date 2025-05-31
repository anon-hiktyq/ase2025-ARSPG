
int unknown();

void foo()  
{
  int c = 0;
  
          
  /* >>> LOOP INVARIANT TO FILL <<< 
     >>> PRECONDITION OF THE LOOP : c == 0 <<< */
  
          /*@
        loop invariant  ((c == 0)) || (1 <= c && c <= 40) ;
          */
          while (unknown()) {
    if (unknown()) {
      if (c != 40) {
        c  = c + 1;
      }
    } else {
      if (c == 40) {
        c  = 1;
      }
    }
  }
          

    /*@ assert (c != 40) ==> (c <= 40);*/
  

}
