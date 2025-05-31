
void func18(int *a, int n) {
    
/* >>> FIXED LOOP INVARIANT <<< */

/*@
  loop invariant 0 <= i; 
  loop invariant (!(i < \at(n, Pre))) ==> ((n == \at(n, Pre))&&(a == \at(a, Pre)));
  loop invariant n == \at(n, Pre);
  loop invariant a == \at(a, Pre);
*/
for (int i = 0; i < n; i++) {
    if (i % 2 == 0) 
        a[i] = 0;
}
            
}
