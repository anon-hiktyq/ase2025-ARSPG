
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __TripleAbsMax
{
    int fabs[3];
    int tmax;
    int* ret;
} TripleAbsMax;

int getThreshold(int n)/*@

Require emp
Ensure (exists i_64, i_64 > n && (0 <= n => 0 <= i_64 && i_64 <= n + 1) && (0 <= n => __return == i_64 * (i_64 - 1) / 2))
*/
{
    int i=0;
    int sum =0;
            
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 <= n@pre) => (0 <= i && i <= n+1) ) &&
((0 <= n@pre) => (sum == (i*(i-1))/2) ) &&
(n == n@pre)
    */
    
    while(i <= n){
        sum += i;
        i++;
    }       
    return sum;
}
void main(TripleAbsMax *pIp)

/*@
With pIp_fabs_l pIp_tmax pIp_ret_v pIp_ret_a
Require store_int_array(pIp->fabs, 3, pIp_fabs_l) && pIp->tmax == pIp_tmax && *(pIp->ret) == pIp_ret_v && (pIp->ret) == pIp_ret_a
Ensure emp
*/{
    
    int threshold = getThreshold(3);

    int fabsfx1 = pIp->fabs[0];
    int fabsfy2 = pIp->fabs[1];
    int fabsfz3 = pIp->fabs[2];

    if (pIp->fabs[0] < 0)
    {
        fabsfx1 = -pIp->fabs[0];
    }

    if (pIp->fabs[1] < 0)
    {
        fabsfy2 = -pIp->fabs[1];
    }

    if (pIp->fabs[2] < 0)
    {
        fabsfz3 = -pIp->fabs[2];
    }

    if (fabsfx1 > fabsfy2)
    {
        pIp->tmax = fabsfx1;
    }
    else
    {
        pIp->tmax = fabsfy2;
    }

    if (fabsfz3 > pIp->tmax)
    {
        pIp->tmax = fabsfz3;
    }


    if (pIp->tmax > threshold)
    {
        *(pIp->ret) = pIp->tmax;
    }
}