
/*@
    requires \valid(arr + (0 .. n-1)); // Ensure the pointer 'arr' is valid for the given range
    ensures \forall integer i; 0 <= i < n ==> arr[i] == \old(arr[i]) + c; // Ensure each element is incremented by 'c'
    ensures n == \old(n); // Ensure the size of the array remains unchanged
    ensures c == \old(c); // Ensure the increment value remains unchanged
    ensures arr == \old(arr); // Ensure the pointer 'arr' remains unchanged
    */
void increment_array_by(int* arr, int n, int c) {
    /*@
      loop invariant 0 <= i <= n; // Loop index is within bounds
      loop invariant \forall integer j; 0 <= j < i ==> arr[j] == \old(arr[j]) + c; // Elements up to 'i' have been incremented by 'c'
      loop invariant c == \at(c, Pre); // 'c' remains unchanged
      loop invariant n == \at(n, Pre); // 'n' remains unchanged
      loop invariant arr == \at(arr, Pre); // 'arr' remains unchanged
      loop assigns arr[0 .. n-1]; // The loop modifies elements of 'arr'
      */
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] + c;
    }
}
