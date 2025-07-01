
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct TAG_CONTROLLERIN
{
    
    int 	Up;						
    int 	Ud;					
    int 	fy;					
    
}SController;
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
typedef struct __SoftFaultProceedSP
{

	SDSSData		mDSSData;
	SFWarning		mFWarning;
	SController     mController;
	int				countPublic;
	int				countMode;

} SoftFaultProceedSP;

void SwitchSS(SoftFaultProceedSP *pIp)

/*@
With pIp_mDSSData_stateFlag_A pIp_mDSSData_stateFlag_B pIp_mDSSData_royaw pIp_mDSSData_piyaw pIp_mDSSData_flgSP pIp_mFWarning_CWsp pIp_mFWarning_CWtf pIp_mFWarning_Wsp pIp_mFWarning_Wtf pIp_mFWarning_Wav pIp_mFWarning_flgups pIp_mFWarning_flgModeChange pIp_mFWarning_countAV pIp_mFWarning_countSPLost pIp_mFWarning_countSPSeen pIp_mFWarning_countSPset pIp_mFWarning_countUPSpc pIp_mController_Up pIp_mController_Ud pIp_mController_fy pIp_countPublic pIp_countMode
Require pIp->mDSSData.stateFlag_A == pIp_mDSSData_stateFlag_A && pIp->mDSSData.stateFlag_B == pIp_mDSSData_stateFlag_B && pIp->mDSSData.royaw == pIp_mDSSData_royaw && pIp->mDSSData.piyaw == pIp_mDSSData_piyaw && pIp->mDSSData.flgSP == pIp_mDSSData_flgSP && pIp->mFWarning.CWsp == pIp_mFWarning_CWsp && pIp->mFWarning.CWtf == pIp_mFWarning_CWtf && pIp->mFWarning.Wsp == pIp_mFWarning_Wsp && pIp->mFWarning.Wtf == pIp_mFWarning_Wtf && pIp->mFWarning.Wav == pIp_mFWarning_Wav && pIp->mFWarning.flgups == pIp_mFWarning_flgups && pIp->mFWarning.flgModeChange == pIp_mFWarning_flgModeChange && pIp->mFWarning.countAV == pIp_mFWarning_countAV && pIp->mFWarning.countSPLost == pIp_mFWarning_countSPLost && pIp->mFWarning.countSPSeen == pIp_mFWarning_countSPSeen && pIp->mFWarning.countSPset == pIp_mFWarning_countSPset && pIp->mFWarning.countUPSpc == pIp_mFWarning_countUPSpc && pIp->mController.Up == pIp_mController_Up && pIp->mController.Ud == pIp_mController_Ud && pIp->mController.fy == pIp_mController_fy && pIp->countPublic == pIp_countPublic && pIp->countMode == pIp_countMode
Ensure emp
*/{

    if (pIp->mDSSData.stateFlag_A == 1)
    {
		pIp -> mDSSData.stateFlag_A = 0;
    }
    else
    {
		pIp -> mDSSData.stateFlag_A = 1;
    }

    return;
}