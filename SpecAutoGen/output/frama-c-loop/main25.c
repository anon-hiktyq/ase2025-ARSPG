

/*@
  requires \valid(a + (0 .. n-1)); 
  requires n >= 0; 
  ensures \result == 1 ==> \forall integer k; 0 <= k < n ==> a[k] % 2 == 0; 
  ensures \result == 0 ==> \exists integer k; 0 <= k < n && a[k] % 2 != 0; 
*/

int areElementsEven(int *a, int n) {
    int p = 0;

    /*@
      loop invariant \forall integer k; 0 <= k < p ==> a[k] % 2 == 0;
      loop invariant p >= 0 && p <= n;
      loop invariant n == \at(n, Pre);
      loop invariant a == \at(a, Pre);
      loop assigns p;
      loop variant n - p;
    */
    while (p < n) {
        if (a[p] % 2 != 0) {
            return 0;
        }
        p = p + 1;
    }

    return 1;
}
void main25() {
    int arr[] = {2,4,6,8,10};
    int res = areElementsEven(arr, 5);
    //@ assert res == 1;
}