
/*@ requires a <= m;
    requires j < 1;
*/
void foo(int m,int j,int a) {

    int k = 0;
    
    
    
            
            /*@
          loop invariant  (\at(a, Pre) <= \at(m, Pre) && \at(j, Pre) < 1) ==> (((k == 0)&&(a == \at(a, Pre))&&(j == \at(j, Pre))&&(m == \at(m, Pre))) || ((m == a && \at(m, Pre) < a) || (m == \at(m, Pre) && \at(m, Pre) >= a))) ;
          loop invariant  (\at(a, Pre) <= \at(m, Pre) && \at(j, Pre) < 1) ==> (((k == 0)&&(a == \at(a, Pre))&&(j == \at(j, Pre))&&(m == \at(m, Pre))) || (0 <= k <= 1)) ;
          loop invariant (\at(a, Pre) <= \at(m, Pre) && \at(j, Pre) < 1) ==> (a == \at(a, Pre));
          loop invariant (\at(a, Pre) <= \at(m, Pre) && \at(j, Pre) < 1) ==> (j == \at(j, Pre));
            */
            while ( k < 1) {

        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }
            

  /*@ assert a <= m; */

}
