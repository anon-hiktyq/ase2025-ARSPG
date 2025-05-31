

/*@
    requires \valid(a + (0 .. n-1));
    requires n >= 0;
    ensures \forall integer i; 0 <= i < n ==> a[i] >= 0;
*/
void arrayAbs(int *a, int n) {
    int i = 0;
    
    /*@ 
        loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] >= 0;
        loop invariant a == \at(a, Pre);
        loop assigns i, a[0 .. n-1];
        loop variant n - i;
    */
    while (i < n) {
        if (a[i] < 0) {
            a[i] = -a[i];
        }
        i++;
    }
}

void main5() {
    int arr[5] = {1, -2, 3,- 4, 5};
    arrayAbs(arr, 5);
    //assert arr[1] == 2;
    //assert arr[3] == 4;
}