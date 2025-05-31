

/*@
    requires \valid(arr + (0 .. n-1)); // Ensure the array pointer is valid for the range [0, n-1]
    requires n >= 0; // Ensure the array size is non-negative
    ensures (\result >= 0) ==> (arr[\result] == x); // If the result is a valid index, the element at that index must be equal to x
    ensures (\result == -1) ==> (\forall integer j; 0 <= j < n ==> arr[j] != x); // If the result is -1, x does not exist in the array
*/
int array_find(int* arr, int n, int x) {
    int i = 0;

    /*@
      loop invariant \forall integer j; 0 <= j < i ==> arr[j] != x; // All elements before index i are not equal to x
      loop invariant (0 < \at(n, Pre)) ==> (0 <= i <= n); // Ensure the loop index stays within bounds when n > 0
      loop invariant (!(0 < \at(n, Pre))) ==> ((i == 0)&&(x == \at(x, Pre))&&(n == \at(n, Pre))&&(arr == \at(arr, Pre))); // Special case when n == 0
      loop invariant x == \at(x, Pre); // x remains unchanged throughout the loop
      loop invariant n == \at(n, Pre); // n remains unchanged throughout the loop
      loop invariant arr == \at(arr, Pre); // arr pointer remains unchanged throughout the loop
      loop assigns i; // The loop modifies only the variable i
      loop variant n - i; // The loop variant ensures termination by strictly decreasing towards 0
    */
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }

    return -1;
}
void main12() {
    int arr[5] = {1, 2, 3, 4, 5};
    int index = array_find(arr, 5, 3);
    //@ assert index == 2;
}