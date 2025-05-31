
/*@ requires n >= 0; 
    requires k >= 0;
*/
void foo(int n,int k) {
    int i = 0;
    int j = 0;

    /*@ loop invariant 0 <= i <= n + 1;
        loop invariant j == (i * (i + 1)) / 2;
        loop invariant k >= 0;
        loop invariant i + j + k > 2 * (i - 1);
        loop assigns i, j;
        loop variant n - i;
    */
    while (i <= n) {
        i = i + 1;
        j = j + i;
    }
    /*@ assert i + j + k > (2 * n); */;
}
