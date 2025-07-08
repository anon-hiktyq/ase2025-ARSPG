
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct TAG_ATTITUDE_PARA     	
{                                    	
	                                 	
	int 	angle[3];			 
	int 	rate[3]; 			 
	                                 	
}SAttitude;
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
typedef struct __FaultJudgeProceed
{
/* 输入端口 */
	/* 输出端口 */
	int			nouse;
	int			countPublic;
	int			countMode;
	SAttitude			mAttitude;
	SDSSData			mDSSData;
	SController 		mController;
	/* 输入输出端口 */
	SFWarning			mFWarning;
	/* 状态变量 */
	/* 参数变量 */
} FaultJudgeProceed;

void SoftFaultJudgeSP(FaultJudgeProceed *pIp)


/*@
With pIp_nouse pIp_countPublic pIp_countMode pIp_mAttitude_angle_l pIp_mAttitude_angle_0 pIp_mAttitude_angle_1 pIp_mAttitude_angle_2 pIp_mAttitude_rate_l pIp_mAttitude_rate_0 pIp_mAttitude_rate_1 pIp_mAttitude_rate_2 pIp_mDSSData_stateFlag_A pIp_mDSSData_stateFlag_B pIp_mDSSData_royaw pIp_mDSSData_piyaw pIp_mDSSData_flgSP pIp_mController_Up pIp_mController_Ud pIp_mController_fy pIp_mFWarning_CWsp pIp_mFWarning_CWtf pIp_mFWarning_Wsp pIp_mFWarning_Wtf pIp_mFWarning_Wav pIp_mFWarning_flgups pIp_mFWarning_flgModeChange pIp_mFWarning_countAV pIp_mFWarning_countSPLost pIp_mFWarning_countSPSeen pIp_mFWarning_countSPset pIp_mFWarning_countUPSpc
Require pIp->nouse == pIp_nouse && pIp->countPublic == pIp_countPublic && pIp->countMode == pIp_countMode && store_int_array(pIp->mAttitude.angle,3, pIp_mAttitude_angle_l) && pIp_mAttitude_angle_l[0] == pIp_mAttitude_angle_0 && pIp_mAttitude_angle_l[1] == pIp_mAttitude_angle_1 && pIp_mAttitude_angle_l[2] == pIp_mAttitude_angle_2 && store_int_array(pIp->mAttitude.rate,3, pIp_mAttitude_rate_l) && pIp_mAttitude_rate_l[0] == pIp_mAttitude_rate_0 && pIp_mAttitude_rate_l[1] == pIp_mAttitude_rate_1 && pIp_mAttitude_rate_l[2] == pIp_mAttitude_rate_2 && pIp->mDSSData.stateFlag_A == pIp_mDSSData_stateFlag_A && pIp->mDSSData.stateFlag_B == pIp_mDSSData_stateFlag_B && pIp->mDSSData.royaw == pIp_mDSSData_royaw && pIp->mDSSData.piyaw == pIp_mDSSData_piyaw && pIp->mDSSData.flgSP == pIp_mDSSData_flgSP && pIp->mController.Up == pIp_mController_Up && pIp->mController.Ud == pIp_mController_Ud && pIp->mController.fy == pIp_mController_fy && pIp->mFWarning.CWsp == pIp_mFWarning_CWsp && pIp->mFWarning.CWtf == pIp_mFWarning_CWtf && pIp->mFWarning.Wsp == pIp_mFWarning_Wsp && pIp->mFWarning.Wtf == pIp_mFWarning_Wtf && pIp->mFWarning.Wav == pIp_mFWarning_Wav && pIp->mFWarning.flgups == pIp_mFWarning_flgups && pIp->mFWarning.flgModeChange == pIp_mFWarning_flgModeChange && pIp->mFWarning.countAV == pIp_mFWarning_countAV && pIp->mFWarning.countSPLost == pIp_mFWarning_countSPLost && pIp->mFWarning.countSPSeen == pIp_mFWarning_countSPSeen && pIp->mFWarning.countSPset == pIp_mFWarning_countSPset && pIp->mFWarning.countUPSpc == pIp_mFWarning_countUPSpc
Ensure emp
*/{

    if (pIp -> mDSSData.flgSP == 0)
    {
     pIp -> mFWarning.countSPLost++ ;
     pIp -> mFWarning.countSPSeen = 0 ;
    }
    else
    {

     if (pIp -> mFWarning.countSPLost != 0)

     {
      pIp -> mFWarning.countSPSeen++ ;
     }


     if (pIp -> mFWarning.countSPSeen > 2)

     {
      pIp -> mFWarning.countSPLost = 0 ;
      pIp -> mFWarning.countSPSeen = 0 ;
     }

    }

    if (pIp -> mFWarning.countSPLost > 33750)
    {
     pIp -> mFWarning.Wsp = 0xEB ;
     pIp -> mFWarning.countSPLost = 0 ;
     pIp -> mFWarning.countSPset = 0 ;
    }

    return ;
}