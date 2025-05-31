
/*@
requires 0 <= n;
requires n < 1000;
*/
void foo(int n) {

    int i=0;
    int sn=0;
    
    

    
                
                /*@
          loop invariant  (0 <= \at(n, Pre) && \at(n, Pre) < 1000) ==> ((0 <= \at(n, Pre)) ==> (((sn == 0)&&(i == 0)&&(n == \at(n, Pre))) || (1 <= i && i <= n+1))) ;
          loop invariant (0 <= \at(n, Pre) && \at(n, Pre) < 1000) ==> ((!(0 <= \at(n, Pre))) ==> ((sn == 0)&&(i == 0)&&(n == \at(n, Pre))));
          loop invariant (0 <= \at(n, Pre) && \at(n, Pre) < 1000) ==> (n == \at(n, Pre));
                */
                for (i = 1; i <= n; i++) {
        sn = sn + (2);
    }
                
    
    /*@ assert sn == n * (2) || sn == 0;*/
    

}
