

/*@
    requires \valid(arr + (0 .. n-1)); // Ensure the pointer 'arr' is valid for the given range
    requires 0 <= n1 < n; // Ensure n1 is a valid index within the array bounds
    requires 0 <= n2 < n; // Ensure n2 is a valid index within the array bounds
    assigns arr[n1], arr[n2]; // Specify that arr[n1] and arr[n2] are modified
    ensures arr[n1] == \old(arr[n2]) && arr[n2] == \old(arr[n1]); // Ensure the elements at n1 and n2 are swapped
*/
void array_swap(int* arr, int n, int n1, int n2) {
    int temp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = temp;
}
void main27() {
    int arr[5] = {1, 2, 3, 4, 5};
    array_swap(arr, 5, 0, 4);
    //@ assert arr[0] == 5;
    //@ assert arr[1] == 2;
    //@ assert arr[2] == 3;
    //@ assert arr[3] == 4;
    //@ assert arr[4] == 1;
}