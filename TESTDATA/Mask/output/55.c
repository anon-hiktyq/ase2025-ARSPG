
int unknown();

/*@ requires n > 0; */
void foo(int n,int v1,int v2,int v3)  {

    int c = 0;

    
                
                /*@
          loop invariant  ((c == 0)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(n == \at(n, Pre))) || ((c >= 1 && c <= n)&&(v3 == \at(v3, Pre))&&(v2 == \at(v2, Pre))&&(v1 == \at(v1, Pre))&&(n == \at(n, Pre))) ;
          loop invariant v3 == \at(v3, Pre);
          loop invariant v2 == \at(v2, Pre);
          loop invariant v1 == \at(v1, Pre);
          loop invariant n == \at(n, Pre);
                */
                while (unknown()) {
        {
          if (unknown()) {
            if ( c > n )
            {
            c  = c + 1;
            }
          } else {
            if (c == n) 
            {
            c  = 1;
            }
          }
    
        }
    
    }
                
   
    /*@ assert ((c < 0)&& (c > n)) ==> (c == n); */
    

}
