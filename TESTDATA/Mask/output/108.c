
/*@ requires a <= m;*/
void foo(int m,int j,int a,int c) {

    int k = 0;
    
        /*@
          loop invariant (0 < \at(c, Pre)) ==> (((k == 0)&&(c == \at(c, Pre))&&(a == \at(a, Pre))&&(j == \at(j, Pre))&&(m == \at(m, Pre))) || (k > 0 && k <= c && m >= a && c == \at(c, Pre) && a == \at(a, Pre) && j == \at(j, Pre)));
          loop invariant (0 < \at(c, Pre)) ==> (k >= 0 && k <= c);
          loop invariant (!(0 < \at(c, Pre))) ==> ((k == 0)&&(c == \at(c, Pre))&&(a == \at(a, Pre))&&(j == \at(j, Pre))&&(m == \at(m, Pre)));
          loop invariant c == \at(c, Pre);
          loop invariant a == \at(a, Pre);
          loop invariant j == \at(j, Pre);
        */
        while ( k < c) {

            if(m < a) {
                m = a;
            }
        
            k = k + 1;
        }
          /*@ assert a <= m; */
}
