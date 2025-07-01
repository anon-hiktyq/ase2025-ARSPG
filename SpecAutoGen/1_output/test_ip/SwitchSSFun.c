
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct TAG_DSS_DATA
{
 	int stateFlag_A;
 	int stateFlag_B;
 	int royaw;
 	int piyaw;
	int flgSP;
}SDSSData;
typedef struct __SwitchSS
{
	SDSSData			mDSSData;
} SwitchSS;

void SwitchSSFun(SwitchSS *pIp)

/*@
With pIp_mDSSData_stateFlag_A pIp_mDSSData_stateFlag_B pIp_mDSSData_royaw pIp_mDSSData_piyaw pIp_mDSSData_flgSP
Require pIp->mDSSData.stateFlag_A == pIp_mDSSData_stateFlag_A && pIp->mDSSData.stateFlag_B == pIp_mDSSData_stateFlag_B && pIp->mDSSData.royaw == pIp_mDSSData_royaw && pIp->mDSSData.piyaw == pIp_mDSSData_piyaw && pIp->mDSSData.flgSP == pIp_mDSSData_flgSP
Ensure emp
*/{

    if (pIp -> mDSSData.stateFlag_A == 1)
    {

        pIp -> mDSSData.stateFlag_A == 0;
		
    }
    else
    {
        pIp -> mDSSData.stateFlag_A == 1;
    }

    return;
}