

/*@
    requires \valid(arr + (0 .. n-1)); 
    requires n > 0; 
    ensures \forall integer j; 0 <= j < n ==> \result >= arr[j]; 
    ensures \exists integer j; 0 <= j < n && \result == arr[j]; 
*/
int array_max_advanced(int* arr, int n) {
    int max = arr[0];
    
    /*@
        loop invariant 0 <= i <= n; 
        loop invariant (\forall integer k; 0 <= k < i ==> arr[k] <= max); 
        loop invariant n == \at(n, Pre); 
        loop invariant \valid(arr + (0 .. n-1)); 
        loop assigns i, max; 
        loop variant n - i; 
    */
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}
void main13() {
    int arr[5] = {1, 2, 3, 4, 5};
    int max = array_max_advanced(arr, 5);
    //@ assert max >= arr[0];
    //@ assert max >= arr[1];
    //@ assert max >= arr[2];
    //@ assert max >= arr[3];
    //@ assert max >= arr[4];
}