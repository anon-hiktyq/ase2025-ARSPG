
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
