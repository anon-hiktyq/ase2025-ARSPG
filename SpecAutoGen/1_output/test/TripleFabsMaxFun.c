
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __TripleFabsMax
{


 int fx1;
 int fy2;
 int fz3;

 int tmax;
 int* ret;

} TripleFabsMax;

void TripleFabsMaxFun(TripleFabsMax *pIp)

/*@
With pIp_fx1 pIp_fy2 pIp_fz3 pIp_tmax pIp_ret_v
Require pIp->fx1 == pIp_fx1 && pIp->fy2 == pIp_fy2 && pIp->fz3 == pIp_fz3 && pIp->tmax == pIp_tmax && *(pIp->ret) == pIp_ret_v
Ensure emp
*/{

    int fabsfx1 = pIp -> fx1;
    int fabsfy2 = pIp -> fy2;
    int fabsfz3 = pIp -> fz3;


    if (pIp -> fx1 < 0)
    {
        fabsfx1 = -pIp -> fx1;
    }

    if (pIp -> fy2 < 0)
    {
        fabsfy2 = -pIp -> fy2;
    }

    if (pIp -> fz3 < 0)
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

    *(pIp -> ret) = pIp->tmax ;
}