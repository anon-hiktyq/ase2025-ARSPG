typedef struct __TripleAbsMax
{
    int fabs[3];
    int tmax;
    int* ret;
} TripleAbsMax;

/*@
ensures 0 <= n ==> \result == n * (n + 1) / 2);
*/

int getThreshold(int n)
{
    int i=0;
    int sum =0;
            
    /*@
          loop invariant (0 <= \at(n, Pre)) ==> (0 <= i <= n+1) ;
          loop invariant (0 <= \at(n, Pre)) ==> (sum == (i*(i-1))/2) ;
          loop invariant (!(0 <= \at(n, Pre))) ==> ((sum ==0)&&(i == 0)&&(n == \at(n, Pre)));
          loop invariant n == \at(n, Pre);
    */
    while(i <= n){
        sum += i;
        i++;
    }
                   
    return sum;
}