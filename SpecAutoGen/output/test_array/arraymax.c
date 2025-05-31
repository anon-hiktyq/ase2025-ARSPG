
/*@
    requires \valid(a + (0 .. n-1)); // Ensure the pointer 'a' is valid for the given range
    requires n > 0; // Ensure the array has at least one element
    ensures \forall integer j; 0 <= j < n ==> \result >= a[j]; // Ensure the result is greater than or equal to all elements in the array
    ensures \exists integer j; 0 <= j < n && \result == a[j]; // Ensure the result is one of the elements in the array
*/
int arraymax(int *a, int n) {
    int i = 1;
    int max = a[0];
  
    /*@
      loop invariant \forall integer j; 0 <= j < \at(n, Pre) ==> a[j] == \at(a, Pre)[j]; // Array elements remain unchanged
      loop invariant 0 <= i <= n; // Loop index remains within bounds
      loop invariant max == \at(a, Pre)[0] || (\forall integer k; 0 <= k < i ==> max >= a[k]); // max is the greatest value among the elements visited so far
      loop invariant \exists integer k; 0 <= k < i && max == a[k]; // max is one of the elements visited so far
      loop assigns i, max; // Variables modified in the loop
      loop variant n - i; // Strictly decreasing loop variant
    */
    while (i < n) {
        if (max < a[i])
            max = a[i];
        i = i + 1;
    }
            
    return max;
}
