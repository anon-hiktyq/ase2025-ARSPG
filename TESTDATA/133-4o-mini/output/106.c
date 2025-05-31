
    
/*@ requires a <= m;
    requires j < 1;
*/
void foo(int m,int j,int a) {

    int k = 0;
    
    /*@
      loop invariant (\at(a, Pre) <= \at(m, Pre) && \at(j, Pre) < 1) ==> (k >= 0);
      loop invariant (\at(a, Pre) <= \at(m, Pre) && \at(j, Pre) < 1) ==> (m >= \at(a, Pre));
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

    