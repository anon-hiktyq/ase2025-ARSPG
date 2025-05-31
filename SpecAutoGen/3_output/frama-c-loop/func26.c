
int func26(int num) {
    int i = 0;
    int sum = 0;

    /*@
      loop invariant (\at(num, Pre)>0) ==> (num >= 0);
      loop invariant (\at(num, Pre)>0) ==> (sum >= 0);
      loop invariant (!(\at(num, Pre)>0)) ==> ((sum == 0)&&(i == 0)&&(num == \at(num, Pre)));
    */
    while(num>0) {
        i = num % 10;
        sum += i;
        num /= 10;
    }
            
    return sum;
}
