
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct TAG_UPS_2MS
{	
	int flgABChoose;				
    int wPulse;
	int stateFlag[2];				
    
} SThrDistribute;
typedef struct __ThrABAutoChoose
{
	/* 输出端口 */
	SThrDistribute			mThrDistribute;
	/* 输入输出端口 */
	/* 状态变量 */
	/* 参数变量 */
} ThrABAutoChoose;

void ThrABAutoChooseFun(ThrABAutoChoose *pIp)

/*@
With pIp_mThrDistribute_flgABChoose pIp_mThrDistribute_wPulse pIp_mThrDistribute_stateFlag_l pIp_mThrDistribute_stateFlag_0 pIp_mThrDistribute_stateFlag_1
Require pIp->mThrDistribute.flgABChoose == pIp_mThrDistribute_flgABChoose && pIp->mThrDistribute.wPulse == pIp_mThrDistribute_wPulse && store_int_array(pIp->mThrDistribute.stateFlag,2, pIp_mThrDistribute_stateFlag_l) && pIp_mThrDistribute_stateFlag_l[0] == pIp_mThrDistribute_stateFlag_0 && pIp_mThrDistribute_stateFlag_l[1] == pIp_mThrDistribute_stateFlag_1
Ensure (pIp_mThrDistribute_stateFlag_l[1] == 1 && pIp_mThrDistribute_stateFlag_l[0] == 1 && pIp_mThrDistribute_stateFlag_l[0] == pIp_mThrDistribute_stateFlag_0 && pIp_mThrDistribute_stateFlag_l[1] == pIp_mThrDistribute_stateFlag_1 && store_int_array(&pIp->mThrDistribute.stateFlag, 2, pIp_mThrDistribute_stateFlag_l) * (pIp->mThrDistribute.flgABChoose == 204) * (pIp->mThrDistribute.wPulse == pIp_mThrDistribute_wPulse)) || (pIp_mThrDistribute_stateFlag_l[1] == 1 && pIp_mThrDistribute_stateFlag_l[0] == 0 && pIp_mThrDistribute_stateFlag_l[0] != 1 && pIp_mThrDistribute_stateFlag_l[0] == pIp_mThrDistribute_stateFlag_0 && pIp_mThrDistribute_stateFlag_l[1] == pIp_mThrDistribute_stateFlag_1 && store_int_array(&pIp->mThrDistribute.stateFlag, 2, pIp_mThrDistribute_stateFlag_l) * (pIp->mThrDistribute.flgABChoose == 51) * (pIp->mThrDistribute.wPulse == pIp_mThrDistribute_wPulse)) || (pIp_mThrDistribute_stateFlag_l[0] != 0 && pIp_mThrDistribute_stateFlag_l[0] != 1 && pIp_mThrDistribute_stateFlag_l[0] == pIp_mThrDistribute_stateFlag_0 && pIp_mThrDistribute_stateFlag_l[1] == pIp_mThrDistribute_stateFlag_1 && store_int_array(&pIp->mThrDistribute.stateFlag, 2, pIp_mThrDistribute_stateFlag_l) * (pIp->mThrDistribute.flgABChoose == 0) * (pIp->mThrDistribute.wPulse == pIp_mThrDistribute_wPulse)) || (pIp_mThrDistribute_stateFlag_l[1] != 1 && pIp_mThrDistribute_stateFlag_l[0] == 0 && pIp_mThrDistribute_stateFlag_l[0] != 1 && pIp_mThrDistribute_stateFlag_l[0] == pIp_mThrDistribute_stateFlag_0 && pIp_mThrDistribute_stateFlag_l[1] == pIp_mThrDistribute_stateFlag_1 && store_int_array(&pIp->mThrDistribute.stateFlag, 2, pIp_mThrDistribute_stateFlag_l) * (pIp->mThrDistribute.flgABChoose == 0) * (pIp->mThrDistribute.wPulse == pIp_mThrDistribute_wPulse)) || (pIp_mThrDistribute_stateFlag_l[0] != 0 && pIp_mThrDistribute_stateFlag_l[1] != 1 && pIp_mThrDistribute_stateFlag_l[0] == 1 && pIp_mThrDistribute_stateFlag_l[0] == pIp_mThrDistribute_stateFlag_0 && pIp_mThrDistribute_stateFlag_l[1] == pIp_mThrDistribute_stateFlag_1 && store_int_array(&pIp->mThrDistribute.stateFlag, 2, pIp_mThrDistribute_stateFlag_l) * (pIp->mThrDistribute.flgABChoose == 0) * (pIp->mThrDistribute.wPulse == pIp_mThrDistribute_wPulse))
*/
{

    if ((pIp -> mThrDistribute.stateFlag[0] == 1) &&
        (pIp -> mThrDistribute.stateFlag[1] == 1))
    {

        pIp -> mThrDistribute.flgABChoose = 0xCC ;
    }
    else if ((pIp -> mThrDistribute.stateFlag[0] == 0) &&
             (pIp -> mThrDistribute.stateFlag[1] == 1))
    {
        pIp -> mThrDistribute.flgABChoose = 0x33 ;
    }
    else
    {
        pIp -> mThrDistribute.flgABChoose = 0x00 ;
    }

    return ;
}