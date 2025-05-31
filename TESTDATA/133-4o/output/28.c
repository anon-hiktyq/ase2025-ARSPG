
void foo(int n) {

    int x = n;
    
    /*@
      loop invariant (\at(n, Pre) > 0) ==> (((x >= 0)&&(x <= \at(n,Pre))&&(n == \at(n, Pre))) || (x == \at(n, Pre) && n == \at(n, Pre)));
      loop invariant (!(\at(n, Pre) > 0)) ==> ((x == \at(n, Pre))&&(n == \at(n, Pre)));
      loop invariant n == \at(n, Pre);
    */
    while (x > 0) {
        x = x - 1;
    }
    
    /*@ assert (x != 0) ==> (n < 0); */
}
