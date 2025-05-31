
int unknown1();

/*@ 
requires 0 <= n && n < 1000000;
*/
int foo(int n) {
    int i = 0; 
    int a = 0; 
    int b = 0; 
    
    
                
                /*@
          loop invariant  (0 <= \at(n, Pre) && \at(n, Pre) < 1000000) ==> ((0 < \at(n, Pre)) ==> (((b == 0)&&(a == 0)&&(i == 0)&&(n == \at(n, Pre))) || (0 < i <= n))) ;
          loop invariant  (0 <= \at(n, Pre) && \at(n, Pre) < 1000000) ==> ((0 < \at(n, Pre)) ==> (((b == 0)&&(a == 0)&&(i == 0)&&(n == \at(n, Pre))) || (a + b == 3 * i))) ;
          loop invariant  (0 <= \at(n, Pre) && \at(n, Pre) < 1000000) ==> ((0 < \at(n, Pre)) ==> (((b == 0)&&(a == 0)&&(i == 0)&&(n == \at(n, Pre))) || (a + b == 3 * i))) ;
          loop invariant (0 <= \at(n, Pre) && \at(n, Pre) < 1000000) ==> ((!(0 < \at(n, Pre))) ==> ((b == 0)&&(a == 0)&&(i == 0)&&(n == \at(n, Pre))));
          loop invariant (0 <= \at(n, Pre) && \at(n, Pre) < 1000000) ==> (n == \at(n, Pre));
                */
                while (i < n) {
        if (unknown1()) {
            a = a + 1;
            b = b + 2;
        } else {
            a = a + 2;
            b = b + 1;
        }
        i = i + 1;
    }
                

    /*@ assert a + b == 3 * n;*/
    
}
