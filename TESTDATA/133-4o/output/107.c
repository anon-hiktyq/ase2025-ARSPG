
void foo(int m,int j,int a) {

    int k = 0;
    
    /*@
      loop invariant  ((k == 0)&&(a == \at(a, Pre))&&(j == \at(j, Pre))&&(m == \at(m, Pre))) || (k >= 1 && m >= a) ;
      loop invariant a == \at(a, Pre);
      loop invariant j == \at(j, Pre);
    */
    while ( k < 1) {

        if(m < a) {
            m = a;
        }
        
        k = k + 1;
    }
    
    /*@ assert a <= m; */
}
