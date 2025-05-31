

/*@
    requires \valid(a + (0 .. n-1)); // Ensure the pointer 'a' is valid for the given range
    requires n >= 0; // Ensure the array size is non-negative
    ensures \result == 1 ==> \exists integer i; 0 <= i < n && a[i] == x; // If the result is 1, x exists in the array
    ensures \result == 0 ==> \forall integer i; 0 <= i < n ==> a[i] != x; // If the result is 0, x does not exist in the array
*/
int arraySearch4(int *a, int x, int n) {
    int p = 0;

    /*@
      loop invariant 0 <= p <= n; // Ensure p is within valid bounds during the loop
      loop invariant \forall integer i; 0 <= i < p ==> a[i] != x; // Ensure x is not found in the checked portion of the array
      loop invariant n == \at(n, Pre); // Ensure n remains unchanged
      loop invariant x == \at(x, Pre); // Ensure x remains unchanged
      loop invariant a == \at(a, Pre); // Ensure a remains unchanged
      loop assigns p; // The loop modifies only the variable p
      loop variant n - p; // The loop progresses toward termination
    */
    while (p < n) {
        if (a[p] == x) {
            return 1;
        }
        p++;
    }

    return 0;
}

void main4() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = arraySearch4(arr, 3, 5);
    //@ assert sum == 1;
}