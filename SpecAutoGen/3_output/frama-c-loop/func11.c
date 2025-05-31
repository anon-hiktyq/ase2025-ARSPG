
int func11(int n) {
    int sum = 0;
    int i = 0;

    /*@
      loop invariant (0 <= \at(n, Pre)/2) ==> (sum == i * (i - 1));
      loop invariant (0 <= \at(n, Pre)/2) ==> (0 <= i <= n/2 + 1);
      loop invariant (!(0 <= \at(n, Pre)/2)) ==> ((i == 0)&&(sum == 0)&&(n == \at(n, Pre)));
      loop invariant n == \at(n, Pre);
    */
    while(i <= n/2) {
        sum = sum + 2*(i);
        i++;
    }
            
    return sum;
}
