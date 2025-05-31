

/*@
    requires c >= 0; 
    ensures \result == c; 
*/
int func8(int c) {
    int x = c;
    int y = 0;

    /*@
      loop invariant (\at(c, Pre) > 0) ==> (x + y == \at(c, Pre));
      loop invariant (\at(c, Pre) > 0) ==> (y >= 0 && x >= 0);
      loop invariant (!(\at(c, Pre) > 0)) ==> ((y == 0) && (x == \at(c, Pre)) && (c == \at(c, Pre)));
      loop invariant c == \at(c, Pre);
      loop assigns x, y;
      loop variant x;
    */
    while(x > 0) {
        x = x - 1;
        y = y + 1;
    }

    return y;
}
void main8() {
    int t = func8(5);
    //@ assert t == 5;
}