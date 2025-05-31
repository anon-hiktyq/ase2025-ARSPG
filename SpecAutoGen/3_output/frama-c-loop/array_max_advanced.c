
int array_max_advanced(int* arr, int n) {
    int max = arr[0];
    
    /*@
        loop invariant (\forall int k; 0 <= k < i ==> arr[k] <= max);
        loop invariant (i < n) ==> ((n == \at(n, Pre)) && (arr == \at(arr, Pre)));
        loop invariant (!(i < n)) ==> ((\forall int k; 0 <= k < n ==> arr[k] <= max) && (n == \at(n, Pre)) && (arr == \at(arr, Pre)));
        loop invariant n == \at(n, Pre);
        loop invariant arr == \at(arr, Pre);
    */
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}
