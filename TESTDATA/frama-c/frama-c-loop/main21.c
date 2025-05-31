

/*@
    requires \valid(a + (0 .. n-1)); // Ensure the array pointer is valid for the given range
    requires n > 0; // Ensure the array has at least one element
    ensures \result == -1 || (0 <= \result < n && a[\result] == x); // Ensure the result is either -1 or a valid index where the value x is found
    ensures \result == -1 ==> \forall integer i; 0 <= i < n ==> a[i] != x; // If the result is -1, ensure x is not in the array
    ensures \result != -1 ==> a[\result] == x; // If the result is not -1, ensure the result points to the index of x
*/
int binarysearch(int* a, int x, int n) {

    int low = -1;
    int high = n;
    int p;

    /*@
        loop invariant low >= -1 && high <= n; // Ensure low and high remain within valid bounds
        loop invariant low + 1 < high; // Ensure the loop condition is valid
        loop invariant \forall integer i; 0 <= i <= low ==> a[i] < x; // Ensure all elements before 'low' are less than x
        loop invariant \forall integer i; high <= i < n ==> a[i] > x; // Ensure all elements after 'high' are greater than x
        loop invariant \valid(a + (0 .. n-1)); // Ensure the array pointer remains valid
        loop invariant n > 0; // Ensure the array size remains positive
        loop invariant x == \at(x, Pre); // Ensure the value being searched remains unchanged
        loop invariant a == \at(a, Pre); // Ensure the array pointer remains unchanged
        loop variant high - low; // Ensure the loop variant decreases
    */
    while (low + 1 < high) {
        p = (low + high) / 2;
        /*@
            requires \valid(a + p); // Ensure the pointer to a[p] is valid
        */
        if (a[p] == x) 
            return p;
        else 
            if (a[p] < x)
                low = p;
            else 
                high = p;
    }
            
    return -1;
}
void main21() {
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = binarysearch(arr, 3, 5);
    //@ assert arr[sum] == 3;
}