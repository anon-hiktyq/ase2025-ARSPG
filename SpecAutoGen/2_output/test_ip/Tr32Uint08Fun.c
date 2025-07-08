
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __Tr32Uint08
{

	int *			pC;
	int *			pB;
	int *			pA;
	int		  uiresult;
	int *		   ret;

} Tr32Uint08;

void Tr32Uint08Fun(Tr32Uint08 *pIp)

/*@
With pIp_pC_v pIp_pC pIp_pB_v pIp_pB pIp_pA_v pIp_pA pIp_uiresult pIp_ret_v pIp_ret
Require *(pIp->pC) == pIp_pC_v && (pIp->pC) == pIp_pC && *(pIp->pB) == pIp_pB_v && (pIp->pB) == pIp_pB && *(pIp->pA) == pIp_pA_v && (pIp->pA) == pIp_pA && pIp->uiresult == pIp_uiresult && *(pIp->ret) == pIp_ret_v && (pIp->ret) == pIp_ret
Ensure (pIp_pA_v != pIp_pC_v && pIp_pA_v == pIp_pB_v && (pIp->pC == pIp_pC) * (*pIp_pC == (pIp_pA_v & pIp_pB_v | pIp_pA_v & pIp_pC_v | pIp_pB_v & pIp_pC_v)) * (pIp->pB == pIp_pB) * (*pIp_pB == (pIp_pA_v & pIp_pB_v | pIp_pA_v & pIp_pC_v | pIp_pB_v & pIp_pC_v)) * (pIp->pA == pIp_pA) * (*pIp_pA == (pIp_pA_v & pIp_pB_v | pIp_pA_v & pIp_pC_v | pIp_pB_v & pIp_pC_v)) * (pIp->uiresult == (pIp_pA_v & pIp_pB_v | pIp_pA_v & pIp_pC_v | pIp_pB_v & pIp_pC_v)) * (pIp->ret == pIp_ret) * (*pIp_ret == (pIp_pA_v & pIp_pB_v | pIp_pA_v & pIp_pC_v | pIp_pB_v & pIp_pC_v))) || (pIp_pA_v != pIp_pB_v && (pIp->pC == pIp_pC) * (*pIp_pC == (pIp_pA_v & pIp_pB_v | pIp_pA_v & pIp_pC_v | pIp_pB_v & pIp_pC_v)) * (pIp->pB == pIp_pB) * (*pIp_pB == (pIp_pA_v & pIp_pB_v | pIp_pA_v & pIp_pC_v | pIp_pB_v & pIp_pC_v)) * (pIp->pA == pIp_pA) * (*pIp_pA == (pIp_pA_v & pIp_pB_v | pIp_pA_v & pIp_pC_v | pIp_pB_v & pIp_pC_v)) * (pIp->uiresult == (pIp_pA_v & pIp_pB_v | pIp_pA_v & pIp_pC_v | pIp_pB_v & pIp_pC_v)) * (pIp->ret == pIp_ret) * (*pIp_ret == (pIp_pA_v & pIp_pB_v | pIp_pA_v & pIp_pC_v | pIp_pB_v & pIp_pC_v))) || (pIp_pA_v == pIp_pC_v && pIp_pA_v == pIp_pB_v && (pIp->pC == pIp_pC) * (*pIp->pC == pIp_pC_v) * (pIp->pB == pIp_pB) * (*pIp->pB == pIp_pB_v) * (pIp->pA == pIp_pA) * (*pIp->pA == pIp_pA_v) * (pIp->uiresult == pIp_pA_v) * (pIp->ret == pIp_ret) * (*pIp->ret == pIp_pA_v))
*/
{

    int uitemp1 ;
    int uitemp2 ;
    int uitemp3 ;
   

    if ((*(pIp -> pA) == *(pIp -> pB)) && (*(pIp -> pA) == *(pIp -> pC)))
    {
        pIp -> uiresult = *(pIp -> pA) ;
    }
    else
    {
        uitemp1 = *(pIp -> pA) & *(pIp -> pB) ;
        uitemp2 = *(pIp -> pA) & *(pIp -> pC) ;
        uitemp3 = *(pIp -> pB) & *(pIp -> pC) ;
        pIp -> uiresult = uitemp1 | uitemp2 | uitemp3 ;

        *(pIp -> pA) = pIp -> uiresult ;
        *(pIp -> pB) = pIp -> uiresult ;
        *(pIp -> pC) = pIp -> uiresult ;
    }

    *(pIp -> ret) = pIp -> uiresult ;
}