
int unknown();

void foo(int n)  {

    int c = 0;

    
            
            /*@
          loop invariant  ((c == 0)) || (1 <= c <= 4) ;
            */
            while (unknown()) {
        {
          if (unknown()) {
            if ( c != 4 )
            {
            c  = c + 1;
            }
          } else {
            if (c == 4) 
            {
            c  = 1;
            }
          }
    
        }
    
    }
             
          
    /*@ assert  (c != 4 ) ==> (c <= 4); */
  

}
