
int tt(int n)
{
    int i=0;
    int sum =0;

    if( n< 0 || n> 3){
        return 0;
    }
    
    /*@
      loop invariant (!(i <= n)) ==> (sum == (n*(n+1))/2);
    */
    while(i <= n){
        sum += i;
        i++;
    }
            
    return sum;
}
