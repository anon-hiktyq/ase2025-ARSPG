

/*@
    requires n >= 0; // Ensure n is non-negative
    ensures \result >= 1; // Ensure the result is at least 1
    ensures \result == ((n < 7) ? 1 : ((n - 7) / 3) + 1); // Ensure the result matches the expected number of steps
*/

int fun17(int n) {
    int i = 7;
    int x = 1;

    /*@
      loop invariant (7 <= \at(n, Pre)) ==> (x == ((i - 7) / 3) + 1) ;
      loop invariant (7 <= \at(n, Pre)) ==> (i == 7 + 3 * (x - 1)) ;
      loop invariant (!(7 <= \at(n, Pre))) ==> ((x == 1)&&(i == 7)&&(n == \at(n, Pre)));
      loop invariant n == \at(n, Pre);
      loop variant n - i; // Strictly decreasing order with lower bound
    */
    while(i <= n) {
        x += 1;
        i += 3;
    }
            
    return x;
}
int main17() {
    int a = fun17(10);
    //@ assert a == 3;
}