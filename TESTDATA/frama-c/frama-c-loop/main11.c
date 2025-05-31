

/*@
    requires n >= 0; 
    ensures \result == (n/2) * (n/2 + 1); 
*/
int func11(int n) {
    int sum = 0;
    int i = 0;

    /*@
      loop invariant 0 <= i <= n/2 + 1; 
      loop invariant sum == i * (i - 1); 
      loop invariant n == \at(n, Pre); 
      loop variant n/2 - i;
    */
    while(i <= n/2) {
        sum = sum + 2 * i;
        i++;
    }
            
    return sum;
}
void main11() {
    int t = func11(10);
    //@ assert t == 30;
}