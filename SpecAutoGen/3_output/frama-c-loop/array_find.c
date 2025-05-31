
int array_find(int* arr, int n, int x) {
    int i = 0;

    /*@
      loop invariant \forall integer j; 0 <= j < i ==> arr[j] != x;
      loop invariant (0 < \at(n, Pre)) ==> (0 <= i <= n);
      loop invariant (!(0 < \at(n, Pre))) ==> ((i == 0)&&(x == \at(x, Pre))&&(n == \at(n, Pre))&&(arr == \at(arr, Pre)));
      loop invariant x == \at(x, Pre);
      loop invariant n == \at(n, Pre);
      loop invariant arr == \at(arr, Pre);
    */
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }

    return -1;
}
