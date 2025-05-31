
/*@ 
requires 0 <= k && k <= 1;
*/
void  foo(int k) {
    int i,j;
    i = 1;
    j = 1;
   
    /* >>> LOOP INVARIANT TO FILL <<< */
        
    /*@
      loop invariant  (0 <= \at(k, Pre) && \at(k, Pre) <= 1) ==> (((j == 1)&&(i == 1)&&(k == \at(k, Pre))) || (k == \at(k, Pre) - i + 1)) ;
      loop invariant  (0 <= \at(k, Pre) && \at(k, Pre) <= 1) ==> (((j == 1)&&(i == 1)&&(k == \at(k, Pre))) || (i >= 1 && i < 1000000)) ;
      loop invariant  (0 <= \at(k, Pre) && \at(k, Pre) <= 1) ==> (((j == 1)&&(i == 1)&&(k == \at(k, Pre))) || (j == 1 + (i-1)*\at(k, Pre) - (i-2)*(i-1)/2)) ;
    */
    while (i < 1000000) {
        i = i + 1;
        j = j + k;
        k = k - 1;
        /*@ assert 1 <= i + k && i + k <= 2 && i >= 1;*/
    }
}
