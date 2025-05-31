

/*@
  requires \valid(a + (0 .. n-1)); // Ensure the pointer 'a' is valid for the given range
  requires n > 0; // Ensure the array has at least one element
  ensures \forall integer j; 0 <= j < n ==> \result >= a[j]; // Ensure the result is greater than or equal to all elements in the array
  ensures \exists integer j; 0 <= j < n && \result == a[j]; // Ensure the result is one of the elements in the array
*/
int arraymax(int* a, int n) {
  int i = 1;
  int max = a[0];

  /*@
    loop invariant \forall integer j; 0 <= j < n ==> a[j] == \at(a[j], Pre); // Array elements remain unchanged
    loop invariant 1 <= i <= n; // Loop index is within bounds
    loop invariant \forall integer k; 0 <= k < i ==> max >= a[k]; // max is greater than or equal to all elements seen so far
    loop invariant \exists integer k; 0 <= k < i && max == a[k]; // max is one of the elements seen so far
    loop assigns i, max; // Variables modified in the loop
    loop variant n - i; // Loop progresses towards termination
  */
  while (i < n) {
    if (max < a[i]) {
      max = a[i];
    }
    i = i + 1;
  }

  return max;
}
void main22() {
  int arr[5] = {1, 2, 3, 4, 5};
  int sum = arraymax(arr, 5);
  //@ assert sum >= arr[0];
  //@ assert sum >= arr[1];
  //@ assert sum >= arr[2];
  //@ assert sum >= arr[3];
  //@ assert sum >= arr[4];
}