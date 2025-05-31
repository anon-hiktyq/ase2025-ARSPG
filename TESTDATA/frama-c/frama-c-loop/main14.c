

/*@
    requires \valid(a + (0 .. n-1)); 
    requires n >= 0;
    ensures \forall integer i; 0 <= i < n ==> a[i] == \old(a[n-1-i]); 
*/
void reverse(int *a, int n) {
    int i = 0;
    int j = n-1;

    /* >>> FIXED LOOP INVARIANTS <<< */
    /*@
      loop invariant 0 <= i <= n/2; 
      loop invariant n/2 <= j < n; 
      loop invariant \forall integer k; 0 <= k < i ==> a[k] == \old(a[n-1-k]); 
      loop invariant \forall integer k; j < k < n ==> a[k] == \old(a[n-1-k]);
      loop invariant n == \at(n, Pre);
      loop invariant a == \at(a, Pre); 
    */
    while (i < n/2) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

void main14() {
    int arr[5] = {1, 2, 3, 4, 5};
    reverse(arr, 5);
    //@ assert arr[4] == 1;
}