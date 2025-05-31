

/*@
    requires \valid(a + (0 .. n-1)); // Ensure the pointer 'a' is valid for the given range
    requires n > 1; // Ensure the array has at least two elements
    assigns a[1]; // The function modifies the second element of the array
    ensures a[1] == 0; // Ensure the second element of the array is set to zero
    ensures \result == 0; // Ensure the return value is zero
*/

int array_1(int *a, int n) {
    
    a[1] = 0; // Corrected syntax error: added semicolon
    return a[1];
}

void main4() {
    int arr[5] = {1, 2, 3, 4, 5};
    int max = array_1(arr, 5);
    
  }