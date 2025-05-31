
/*@
    requires \true;
    ensures \result >= 0;
    ensures \result == (x >= 0 ? x : -x);
*/
int test(int x) {
    int a = x;
    int y = 0;

    /*@
      loop invariant (\at(x, Pre) != 0) ==> (a + y == \at(x, Pre));
      loop invariant (\at(x, Pre) != 0) ==> (y >= 0);
      loop invariant (!(\at(x, Pre) != 0)) ==> ((y == 0)&&(a == \at(x, Pre))&&(x == \at(x, Pre)));
      loop invariant x == \at(x, Pre);
      loop assigns a, y;
      loop variant a >= 0 ? a : -a;
    */
    while(a != 0) {
        y = y + 1;
        a = a - 1;
    }
            
    return y;
}

/*@
    ensures \result == 0;
*/
int main5() {
    int num = test(3);
    //@ assert num == 3;
    return 0;
}
