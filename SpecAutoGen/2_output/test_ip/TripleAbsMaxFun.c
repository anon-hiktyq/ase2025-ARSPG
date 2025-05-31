
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

void TripleAbsMaxFun(TripleAbsMax *pIp)

/*@
With pIp_fabs_l pIp_tmax pIp_ret_v
Require store_int_array(pIp->fabs, 3, pIp_fabs_l) && pIp->tmax == pIp_tmax && *(pIp->ret) == pIp_ret_v
Ensure emp
*/{
    int threshold =0;

    int i=0;
   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    exists  pIp_fabs_l ,    
    store_int_array(pIp->fabs, 3, pIp_fabs_l) &&
    (logic integer pIp_fabs_l_l[3]
          logic integer pIp_tmax
          logic integer pIp_ret_v) &&
(store_int_array(&pIp->fabs, 3, pIp_fabs_l)) &&
((0<pIp@pre->tmax) => (threshold == (i * (i - 1)) / 2)) &&
((0<pIp@pre->tmax) => (0 <= i && i <= pIp@pre->tmax)) &&
((!(0<pIp@pre->tmax)) => ((i == 0)&&(threshold == 0)&&(pIp == pIp@pre)&&(pIp@pre->tmax == pIp_tmax)&&(*pIp@pre->ret == pIp_ret_v))) &&
(pIp == pIp@pre) &&
(pIp@pre->tmax == pIp_tmax) &&
(*pIp@pre->ret == pIp_ret_v)
    */
    
            while(i<pIp->tmax){
        threshold= threshold+i;
        i++;
    }

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