

/*@
    requires num >= 0; // Ensure the input number is non-negative
    ensures \result >= 0; // Ensure the result is non-negative
    ensures \result == (\sum integer k; 0 <= k < \old(num) && \old(num) > 0; (\old(num) / \pow(10, k)) % 10); // Ensure the result equals the sum of the digits of the original number
*/
int func26(int num) {
    int i = 0;
    int sum = 0;

    /*@
      loop invariant num >= 0; // Ensure num remains non-negative during the loop
      loop invariant sum >= 0; // Ensure sum remains non-negative during the loop
      loop invariant \forall integer k; 0 <= k < (\old(num) - num) ==> sum == (\sum integer j; 0 <= j < k; (\old(num) / \pow(10, j)) % 10); // Ensure sum accumulates the digits processed so far
      loop variant num; // Ensure num strictly decreases with each iteration
    */
    while(num > 0) {
        i = num % 10;
        sum += i;
        num /= 10;
    }
            
    return sum;
}
void main26() {
    int t = func26(123);
    //@ assert t == 6;
}