
/*@ requires n >= 0; 
    requires k >= 0;
*/
void foo(int n,int k) {
    int i = 0;
    int j = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant j == i * (i + 1) / 2;
      loop invariant i <= n + 1 ;
      loop invariant (!(0 <= \at(n, Pre))) ==> ((j == 0)&&(i == 0)&&(k == \at(k, Pre))&&(n == \at(n, Pre)));
      loop invariant k == \at(k, Pre);
      loop invariant n == \at(n, Pre);
    */
    while (i <= n) {
        i = i + 1;
        j = j + i;
    }
}
