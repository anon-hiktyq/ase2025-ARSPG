
typedef struct __TripleFabsMax
{
    int fabs[3];
    int tmax;
    int* ret;
} TripleFabsMax;

/*@
    requires n >= 0; // Ensure n is non-negative
    ensures \result == (n * (n + 1)) / 2; // The result is the sum of the first n natural numbers
*/
int getThreshold (int n) {
    int i = 0;
    int sum = 0;
    
    /*@
      loop invariant 0 <= i <= n + 1;
      loop invariant sum == (i * (i - 1)) / 2;
      loop invariant n == \at(n, Pre);
      loop assigns i, sum;
      loop variant n - i;
    */
    while (i <= n) {
        sum += i;
        i++;
    }
    
    return sum;
}

/*@
    requires \valid(pIp) && \valid(pIp->ret); // Ensure the pointer pIp and pIp->ret are valid
    ensures \forall integer i; 0 <= i < 3 ==> pIp->fabs[i] >= 0; // Ensure all elements in fabs are non-negative
    ensures \result == \old(pIp->tmax) || \result == 0; // Ensure the result is either the old tmax or zero
*/
void TripleFabsMaxFun_(TripleFabsMax *pIp)
{
    int threshold = getThreshold(3);

    int fabsfx1 = pIp -> fabs[0];
    int fabsfy2 = pIp -> fabs[1];
    int fabsfz3 = pIp -> fabs[2];

    if (pIp -> fabs[0] < 0)
    {
        fabsfx1 = -pIp -> fabs[0];
    }

    if (pIp -> fabs[1] < 0)
    {
        fabsfy2 = -pIp -> fabs[1];
    }

    if (pIp -> fabs[2] < 0)
    {
        fabsfz3 = -pIp -> fabs[2];
    }

    if (fabsfx1 > fabsfy2)
    {
        pIp -> tmax = fabsfx1 ;
    }
    else
    {
        pIp -> tmax = fabsfy2 ;
    }

    if (fabsfz3 > pIp -> tmax)
    {
        pIp -> tmax = fabsfz3 ;
    }

    if (pIp->tmax > threshold){
        *(pIp -> ret) = pIp->tmax;
    }else{
        *(pIp -> ret) = 0;
    }
}
