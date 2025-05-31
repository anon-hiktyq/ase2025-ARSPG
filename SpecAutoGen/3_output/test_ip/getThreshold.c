
int getThreshold(int n){
    int i=0;
    int sum =0;
            
    /*@
          loop invariant (0 <= \at(n, Pre)) ==> (0 <= i <= n+1) ;
          loop invariant (0 <= \at(n, Pre)) ==> (sum == (i*(i-1))/2) ;
          loop invariant n == \at(n, Pre);
    */
    while(i <= n){
        sum += i;
        i++;
    }
                   
    return sum;
}
