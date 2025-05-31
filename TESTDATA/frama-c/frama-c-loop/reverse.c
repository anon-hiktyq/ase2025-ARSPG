
/*@
    requires \valid(a + (0 .. n-1)); /* Ensure the pointer 'a' is valid for the given range */
    requires n >= 0; /* Ensure the array size is non-negative */
    assigns a[0 .. n-1]; /* The function modifies the elements of the array */
    ensures \forall integer i; 0 <= i < n ==> a[i] == \old(a[n-1-i]); /* Ensure the array is reversed */
*/
void reverse(int *a, int n) {
    int i = 0;
    int j = n-1;

    /* >>> FIXED LOOP INVARIANTS <<< */
    /*@
      loop invariant 0 <= i <= n/2; /* Ensure 'i' stays within valid bounds */
      loop invariant n/2 <= j < n; /* Ensure 'j' stays within valid bounds */
      loop invariant \forall integer k; 0 <= k < i ==> a[k] == \old(a[n-1-k]); /* Ensure elements up to 'i' are reversed */
      loop invariant \forall integer k; j < k < n ==> a[k] == \old(a[n-1-k]); /* Ensure elements from 'j+1' to 'n-1' are reversed */
      loop invariant n == \at(n, Pre); /* Ensure 'n' remains unchanged */
      loop invariant a == \at(a, Pre); /* Ensure 'a' remains unchanged */
      assigns a[0 .. n-1]; /* The loop modifies the array elements */
      decreases j - i; /* Ensure the loop progresses toward termination */
    */
    while (i < n/2) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}
