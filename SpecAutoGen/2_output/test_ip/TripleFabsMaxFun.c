
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __TripleFabsMax
{


 int fx[3];
 int tmax;
 int* ret;



} TripleFabsMax;

void TripleFabsMaxFun(TripleFabsMax *pIp)


{

    int fabsfx1 = pIp -> fx[0];
    int fabsfy2 = pIp -> fy[1];
    int fabsfz3 = pIp -> fz[2];

    


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