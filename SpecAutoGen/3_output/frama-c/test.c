
int test(int x) {
    int a = x;
    int y = 0;

    /*@
      loop invariant (\at(x, Pre) != 0) ==> (a + y == \at(x, Pre)) ;
      loop invariant (\at(x, Pre) != 0) ==> (y >= 0) ;
      loop invariant (!(\at(x, Pre) != 0)) ==> ((y == 0)&&(a == \at(x, Pre))&&(x == \at(x, Pre)));
      loop invariant x == \at(x, Pre);
    */
    while(a != 0) {
        y = y + 1;
        a = a - 1;
    }
            
    return y;
}
