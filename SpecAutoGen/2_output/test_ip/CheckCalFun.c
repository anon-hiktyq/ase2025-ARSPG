
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __CheckCal
{

	int		len;
	int*	pkv;
	int     chksum;
	
} CheckCal;

void CheckCalFun(CheckCal *pIp)

/*@
With pIp_len pIp_pkv_v pIp_pkv pIp_chksum
Require pIp->len == pIp_len && *(pIp->pkv) == pIp_pkv_v && (pIp->pkv) == pIp_pkv && pIp->chksum == pIp_chksum
Ensure emp
*/{

	int i;
	int chksum = 0;


 	/*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (pIp->pkv == pIp->pkv@pre) &&
(pIp->len == pIp->len@pre) &&
(pIp == pIp@pre)
    */
    
    for(i=0; i<pIp->len; i++)
    {
        chksum = chksum + pIp->pkv[i];
    }

	return;
}