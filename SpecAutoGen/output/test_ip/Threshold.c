typedef struct __TripleAbsMax
{


 int fabs[3];
 int tmax;
 int* ret;



} TripleAbsMax;

/*@

ensures \exists int pre, i_66;  i_66 > n && 0 <= i_66 && i_66 <= n + 1  ==>  \result == i_66 * (i_66 - 1) / 2 && (!(i_66 <= n) ==> \result == n * (n + 1) / 2) && \old(n) >= 0 ;

ensures n > 5  ==>  \result == 0;

ensures n < 0 && n <= 5  ==>  \result == 0;

*/

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