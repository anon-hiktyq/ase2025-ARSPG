

/*@
    requires \valid(a + (0 .. n-1)); 
    requires n >= 0; 
    ensures \forall integer i; 0 <= i < n && i % 2 == 0 ==> a[i] == 0; 
    ensures \forall integer i; 0 <= i < n && i % 2 != 0 ==> a[i] == \old(a[i]);
    */
void func18(int *a, int n) {
    
/* >>> FIXED LOOP INVARIANT <<< */

/*@
  loop invariant 0 <= i; 
  loop invariant i <= n;
  loop invariant \forall integer j; 0 <= j < i && j % 2 == 0 ==> a[j] == 0;
  loop invariant \forall integer j; 0 <= j < i && j % 2 != 0 ==> a[j] == \at(a[j], Pre);
  loop invariant n == \at(n, Pre);
  loop invariant a == \at(a, Pre);
*/
for (int i = 0; i < n; i++) {
    if (i % 2 == 0) 
        a[i] = 0;
}
            
}
void main18() {
    int arr[5] = {1, 2, 3, 4, 5};
    func18(arr, 5);
    //@ assert arr[0] == 0;
    //@ assert arr[2] == 0;
    //@ assert arr[4] == 0;
}