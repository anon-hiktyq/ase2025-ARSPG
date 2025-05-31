
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

void main(TripleFabsMax *pIp)

/*@
With pIp_fabs_l pIp_fabs_0 pIp_fabs_1 pIp_fabs_2 pIp_tmax pIp_ret_v pIp_ret_a
Require store_int_array(pIp->fabs,3, pIp_fabs_l) && pIp_fabs_l[0] == pIp_fabs_0 && pIp_fabs_l[1] == pIp_fabs_1 && pIp_fabs_l[2] == pIp_fabs_2 && pIp->tmax == pIp_tmax && *(pIp->ret) == pIp_ret_v && (pIp->ret) == pIp_ret_a
Ensure (pIp_fabs_l[2] <= pIp_fabs_l[1] && pIp_fabs_l[0] <= pIp_fabs_l[1] && pIp_fabs_l[0] == pIp_fabs_0 && pIp_fabs_l[1] == pIp_fabs_1 && pIp_fabs_l[2] == pIp_fabs_2 && store_int_array(&pIp->fabs, 3, pIp_fabs_l) * (pIp->tmax == pIp_fabs_l[1]) * (pIp->ret == pIp_ret_a) * (*pIp_ret_a == pIp_fabs_l[1])) || (pIp_fabs_l[2] <= pIp_fabs_l[0] && pIp_fabs_l[0] > pIp_fabs_l[1] && pIp_fabs_l[0] == pIp_fabs_0 && pIp_fabs_l[1] == pIp_fabs_1 && pIp_fabs_l[2] == pIp_fabs_2 && store_int_array(&pIp->fabs, 3, pIp_fabs_l) * (pIp->tmax == pIp_fabs_l[0]) * (pIp->ret == pIp_ret_a) * (*pIp_ret_a == pIp_fabs_l[0])) || (pIp_fabs_l[2] > pIp_fabs_l[0] && pIp_fabs_l[0] > pIp_fabs_l[1] && pIp_fabs_l[0] == pIp_fabs_0 && pIp_fabs_l[1] == pIp_fabs_1 && pIp_fabs_l[2] == pIp_fabs_2 && store_int_array(&pIp->fabs, 3, pIp_fabs_l) * (pIp->tmax == pIp_fabs_l[2]) * (pIp->ret == pIp_ret_a) * (*pIp_ret_a == pIp_fabs_l[2])) || (pIp_fabs_l[2] > pIp_fabs_l[1] && pIp_fabs_l[0] <= pIp_fabs_l[1] && pIp_fabs_l[0] == pIp_fabs_0 && pIp_fabs_l[1] == pIp_fabs_1 && pIp_fabs_l[2] == pIp_fabs_2 && store_int_array(&pIp->fabs, 3, pIp_fabs_l) * (pIp->tmax == pIp_fabs_l[2]) * (pIp->ret == pIp_ret_a) * (*pIp_ret_a == pIp_fabs_l[2]))
*/
{

    int fabsfx1 = pIp->fabs[0];
    int fabsfy2 = pIp->fabs[1];
    int fabsfz3 = pIp->fabs[2];


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

    *(pIp -> ret) = pIp->tmax ;
}