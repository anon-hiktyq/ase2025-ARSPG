
int mul10(int a, int b) {
    int x = a, y = b, prod = 0;

    /*@
      loop invariant (!(\at(a, Pre) >= 0)) ==> ((prod == 0)&&(y == \at(b, Pre))&&(x == \at(a, Pre))&&(b == \at(b, Pre))&&(a == \at(a, Pre)));
      loop invariant y == \at(b, Pre);
      loop invariant b == \at(b, Pre);
      loop invariant a == \at(a, Pre);
    */
    while(x >= 0) {
        prod = prod + y;
        x--;
    }
            
    return prod;
}
