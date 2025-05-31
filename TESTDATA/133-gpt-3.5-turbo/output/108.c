
/*@ requires a <= m;*/
void foo(int m,int j,int a,int c) {

    int k = 0;
    
            /*@
          loop invariant  (\at(a, Pre) <= \at(m, Pre)) ==> ((0 < \at(c, Pre)) ==> (((k == 0)&&(c == \at(c, Pre))&&(a == \at(a, Pre))&&(j == \at(j, Pre))&&(m == \at(m, Pre))) || (m >= a))) ;
          loop invariant  (\at(a, Pre) <= \at(m, Pre)) ==> ((0 < \at(c, Pre)) ==> (((k == 0)&&(c == \at(c, Pre))&&(a == \at(a, Pre))&&(j == \at(j, Pre))&&(m == \at(m, Pre))) || (k <= c))) ; 
          loop invariant (\at(a, Pre) <= \at(m, Pre)) ==> ((!(0 < \at(c, Pre))) ==> ((k == 0)&&(c == \at(c, Pre))&&(a == \at(a, Pre))&&(j == \at(j, Pre))&&(m == \at(m, Pre))));
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
