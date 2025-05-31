

/*@
  requires \valid(a + (0 .. n-1)); 
  requires n > 0; 
  ensures \result == \sum(0, n-1, \lambda integer i; a[i]); 
  ensures \forall integer i; 0 <= i < n ==> \result >= a[i]; 
*/
int sumArray(int *a, int n) {
    int p = 0, sum = 0;

    /*@
      loop invariant \forall integer k; 0 <= k < p ==> \at(a, Pre)[k] == a[k];
      loop invariant (0 < \at(n, Pre)) ==> (0 <= p <= \at(n, Pre));
      loop invariant (!(0 < \at(n, Pre))) ==> ((sum == 0)&&(p == 0)&&(n == \at(n, Pre))&&(a == \at(a, Pre)));
      loop invariant sum == \sum(0, p-1, \lambda integer i; a[i]);
      loop invariant n == \at(n, Pre);
      loop invariant a == \at(a, Pre);
      loop variant n - p;
    */
    while (p < n) {
        sum = sum + a[p];
        p++;
    }

    return sum;
}
void main20() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = sumArray(arr, 5);
    //@ assert sum == 15;
}