
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct TAG_FAULT_WARNING
{
 	int CWsp;
 	int CWtf;

    int Wsp;
    int Wtf;
    int Wav;

    int flgups;
    int flgModeChange;

    int countAV;
    int countSPLost;
    int countSPSeen;
    int countSPset;
    int countUPSpc;

} SFWarning;
typedef struct TAG_DSS_DATA
{
 	int stateFlag_A;
 	int stateFlag_B;
 	int royaw;
 	int piyaw;
	int flgSP;
}SDSSData;
typedef struct TAG_CONTROLLERIN
{
    
    int 	Up;						
    int 	Ud;					
    int 	fy;					
    
}SController;
typedef struct __SAMSubModeRoll
{
/* 输入端口 */
	const SDSSData * pSDS;
	int	  countPublic;
	int   countMode;
	int   flgMode;
	/* 输出端口 */
	SDSSData		mDSSData;
	/* 输入输出端口 */
	SController*	pCtrl0;
	SController*	pCtrl1;
	SController*	pCtrl2;
	int			    flgPRSAM;
	SFWarning		mFWarning;
	/* 状态变量 */
	/* 参数变量 */
} SAMSubModeRoll;

void SwitchSSR(SAMSubModeRoll *pIp)

/*@
With pIp_pSDS_stateFlag_A pIp_pSDS_stateFlag_B pIp_pSDS_royaw pIp_pSDS_piyaw pIp_pSDS_flgSP pIp_countPublic pIp_countMode pIp_flgMode pIp_mDSSData_stateFlag_A pIp_mDSSData_stateFlag_B pIp_mDSSData_royaw pIp_mDSSData_piyaw pIp_mDSSData_flgSP pIp_pCtrl0_Up pIp_pCtrl0_Ud pIp_pCtrl0_fy pIp_pCtrl1_Up pIp_pCtrl1_Ud pIp_pCtrl1_fy pIp_pCtrl2_Up pIp_pCtrl2_Ud pIp_pCtrl2_fy pIp_flgPRSAM pIp_mFWarning_CWsp pIp_mFWarning_CWtf pIp_mFWarning_Wsp pIp_mFWarning_Wtf pIp_mFWarning_Wav pIp_mFWarning_flgups pIp_mFWarning_flgModeChange pIp_mFWarning_countAV pIp_mFWarning_countSPLost pIp_mFWarning_countSPSeen pIp_mFWarning_countSPset pIp_mFWarning_countUPSpc
Require pIp->pSDS->stateFlag_A == pIp_pSDS_stateFlag_A && pIp->pSDS->stateFlag_B == pIp_pSDS_stateFlag_B && pIp->pSDS->royaw == pIp_pSDS_royaw && pIp->pSDS->piyaw == pIp_pSDS_piyaw && pIp->pSDS->flgSP == pIp_pSDS_flgSP && pIp->countPublic == pIp_countPublic && pIp->countMode == pIp_countMode && pIp->flgMode == pIp_flgMode && pIp->mDSSData.stateFlag_A == pIp_mDSSData_stateFlag_A && pIp->mDSSData.stateFlag_B == pIp_mDSSData_stateFlag_B && pIp->mDSSData.royaw == pIp_mDSSData_royaw && pIp->mDSSData.piyaw == pIp_mDSSData_piyaw && pIp->mDSSData.flgSP == pIp_mDSSData_flgSP && pIp->pCtrl0->Up == pIp_pCtrl0_Up && pIp->pCtrl0->Ud == pIp_pCtrl0_Ud && pIp->pCtrl0->fy == pIp_pCtrl0_fy && pIp->pCtrl1->Up == pIp_pCtrl1_Up && pIp->pCtrl1->Ud == pIp_pCtrl1_Ud && pIp->pCtrl1->fy == pIp_pCtrl1_fy && pIp->pCtrl2->Up == pIp_pCtrl2_Up && pIp->pCtrl2->Ud == pIp_pCtrl2_Ud && pIp->pCtrl2->fy == pIp_pCtrl2_fy && pIp->flgPRSAM == pIp_flgPRSAM && pIp->mFWarning.CWsp == pIp_mFWarning_CWsp && pIp->mFWarning.CWtf == pIp_mFWarning_CWtf && pIp->mFWarning.Wsp == pIp_mFWarning_Wsp && pIp->mFWarning.Wtf == pIp_mFWarning_Wtf && pIp->mFWarning.Wav == pIp_mFWarning_Wav && pIp->mFWarning.flgups == pIp_mFWarning_flgups && pIp->mFWarning.flgModeChange == pIp_mFWarning_flgModeChange && pIp->mFWarning.countAV == pIp_mFWarning_countAV && pIp->mFWarning.countSPLost == pIp_mFWarning_countSPLost && pIp->mFWarning.countSPSeen == pIp_mFWarning_countSPSeen && pIp->mFWarning.countSPset == pIp_mFWarning_countSPset && pIp->mFWarning.countUPSpc == pIp_mFWarning_countUPSpc
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