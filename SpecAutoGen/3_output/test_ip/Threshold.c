
int Threshold(int n)
{
    int i=0;
    int sum =0;

    if (n > 5 || n < 0){
        return 0;
    } 
    
    /*@
      loop invariant 0 <= i <= n+1;
      loop invariant sum == (i*(i-1))/2;
      loop invariant (!(i <= n)) ==> (sum == (n*(n+1))/2);
    */
    while(i <= n){
        sum += i;
        i++;
    }
            
    return sum;
}
