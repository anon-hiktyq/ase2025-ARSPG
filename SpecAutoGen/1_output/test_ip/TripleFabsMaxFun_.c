
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __TripleFabsMax
{


 int fabs[3];
 int tmax;
 int* ret;



} TripleFabsMax;

int getThreshold (int n)/*@

Require emp
Ensure Results(__return)
*/
{

    int i=0;
    int sum =0;
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 <= n@pre) => (0 <= i && i <= n+1) ) &&
((0 <= n@pre) => (sum == (i*(i-1))/2) ) &&
((!(0 <= n@pre)) => ((sum == 0)&&(i == 0)&&(n == n@pre))) &&
(n == n@pre)
    */
    
            while(i <= n){
        sum += i;
        i++;
    }
    return sum;
   
}
void TripleFabsMaxFun_(TripleFabsMax *pIp)

/*@
With pIp_fabs_l pIp_tmax pIp_ret_v
Require store_int_array(pIp->fabs, 3, pIp_fabs_l) && pIp->tmax == pIp_tmax && *(pIp->ret) == pIp_ret_v
Ensure emp
*/{

    int threshold = getThreshold(3);

    int fabsfx1 = pIp -> fabs[0];
    int fabsfy2 = pIp -> fabs[1];
    int fabsfz3 = pIp -> fabs[2];

     if (pIp -> fabs[0] < 0)
    {
        fabsfx1 = -pIp -> fx1;
    }

    if (pIp -> fabs[1] < 0)
    {
        fabsfy2 = -pIp -> fy2;
    }

    if (pIp -> fabs[2] < 0)
    {
        fabsfz3 = -pIp -> fz3;
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