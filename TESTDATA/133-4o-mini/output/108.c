
/*@ requires a <= m;*/
void foo(int m,int j,int a,int c) {

    int k = 0;
    
            /*@
          loop invariant  (\at(a, Pre) <= \at(m, Pre)) ==>  (k >= 0) && (m >= \at(a, Pre)) ; // Weakening the invariant 
          loop invariant  (\at(a, Pre) <= \at(m, Pre)) ==> ((0 < \at(c, Pre)) ==> (k <= \at(c, Pre)));
          loop invariant (\at(a, Pre) <= \at(m, Pre)) ==> (c == \at(c, Pre));
          loop invariant (\at(a, Pre) <= \at(m, Pre)) ==> (a == \at(a, Pre));
          loop invariant (\at(a, Pre) <= \at(m, Pre)) ==> (j == \at(j, Pre));
            */
            while ( k < c) {

        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }
            

  /*@ assert a <= m; */

}
