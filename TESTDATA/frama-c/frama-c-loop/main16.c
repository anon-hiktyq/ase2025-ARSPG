

/*@
    requires \valid(a + (0 .. n-1));
    requires \valid(b + (0 .. n-1));
    requires n > 0;
    ensures \result == 1 <==> \forall integer k; 0 <= k < n ==> a[k] == b[k];
    ensures \result == 0 <==> \exists integer k; 0 <= k < n && a[k] != b[k];
*/
int check(int *a, int *b, int n) {

    /*@
      loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
      loop invariant (!(i < \at(n, Pre))) ==> ((n == \at(n, Pre))&&(b == \at(b, Pre))&&(a == \at(a, Pre)));
      loop invariant n == \at(n, Pre);
      loop invariant b == \at(b, Pre);
      loop invariant a == \at(a, Pre);
      loop variant n - i;
    */
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}
int main16() {
    int a[] = {1,2,3,4,5};
    int b[] = {1,2,3,4,5};
    int res = check(a, b, 5);
    //@ assert res == 1;
}