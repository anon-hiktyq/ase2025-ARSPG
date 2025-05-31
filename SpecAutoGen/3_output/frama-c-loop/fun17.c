
int fun17(int n) {
    int i = 7;
    int x = 1;

    /*@
      loop invariant (7 <= \at(n, Pre)) ==> (x == ((i - 7) / 3) + 1) ;
      loop invariant (7 <= \at(n, Pre)) ==> (i == 7 + 3 * (x - 1)) ;
      loop invariant (!(7 <= \at(n, Pre))) ==> ((x == 1)&&(i == 7)&&(n == \at(n, Pre)));
      loop invariant n == \at(n, Pre);
    */
    while(i <= n) {
        x += 1;
        i += 3;
    }
            
    return x;
}
