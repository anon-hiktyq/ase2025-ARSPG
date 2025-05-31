
void foo(int m,int j,int a,int c) {

    int k = 0;
    
            /*@
          loop invariant (0 < \at(c, Pre)) ==> (((k == 0)&&(c == \at(c, Pre))&&(a == \at(a, Pre))&&(j == \at(j, Pre))&&(m == \at(m, Pre))) || (m >= a));
          loop invariant (0 < \at(c, Pre)) ==> (((k == 0)&&(c == \at(c, Pre))&&(a == \at(a, Pre))&&(j == \at(j, Pre))&&(m == \at(m, Pre))) || (0 < k && k <= c));
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
            
  /*@ assert (c > 0 ) ==> (a <= m); */
}
