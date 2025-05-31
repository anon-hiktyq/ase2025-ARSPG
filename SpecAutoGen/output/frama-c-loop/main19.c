

/*@
    requires \valid(a + (0 .. n-1)); // Ensure the pointer 'a' is valid for the given range
    ensures \forall integer j; 0 <= j < n ==> a[j] == 2 * \old(a[j]); // Ensure each element in the array is doubled
    ensures n == \old(n); // Ensure the size of the array remains unchanged
    ensures a == \old(a); // Ensure the pointer 'a' remains unchanged
    */
void arrayDouble(int *a, unsigned int n) {
    int p = 0;

    /*@
      loop invariant (0 < \at(n, Pre)) ==> (0 <= p <= \at(n, Pre));
      loop invariant (!(0 < \at(n, Pre))) ==> ((p == 0)&&(n == \at(n, Pre))&&(a == \at(a, Pre)));
      loop invariant n == \at(n, Pre);
      loop invariant a == \at(a, Pre);
      loop invariant \forall integer j; 0 <= j < p ==> a[j] == 2 * \old(a[j]); // Ensure elements up to index p are doubled
      loop assigns p, a[0 .. n-1]; // Specify the variables modified by the loop
    */
    while (p < n) {
        a[p] = a[p] * 2;
        p = p + 1;
    }
}
int main19() {
    int arr[] = {0,1,2,3,4,5};
    arrayDouble(arr, 6);
    //@ assert arr[0] == 0;
    //@ assert arr[1] == 2;
    //@ assert arr[2] == 4;
    //@ assert arr[3] == 6;
    //@ assert arr[4] == 8;
    //@ assert arr[5] == 10;
}