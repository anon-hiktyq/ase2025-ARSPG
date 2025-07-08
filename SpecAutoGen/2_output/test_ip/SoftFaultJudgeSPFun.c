
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
typedef struct __SoftFaultJudgeSP
{

 SDSSData mDSSData;
 SFWarning mFWarning;


} SoftFaultJudgeSP;

void SoftFaultJudgeSPFun(SoftFaultJudgeSP *pIp)


/*@
With pIp_mDSSData_stateFlag_A pIp_mDSSData_stateFlag_B pIp_mDSSData_royaw pIp_mDSSData_piyaw pIp_mDSSData_flgSP pIp_mFWarning_CWsp pIp_mFWarning_CWtf pIp_mFWarning_Wsp pIp_mFWarning_Wtf pIp_mFWarning_Wav pIp_mFWarning_flgups pIp_mFWarning_flgModeChange pIp_mFWarning_countAV pIp_mFWarning_countSPLost pIp_mFWarning_countSPSeen pIp_mFWarning_countSPset pIp_mFWarning_countUPSpc
Require pIp->mDSSData.stateFlag_A == pIp_mDSSData_stateFlag_A && pIp->mDSSData.stateFlag_B == pIp_mDSSData_stateFlag_B && pIp->mDSSData.royaw == pIp_mDSSData_royaw && pIp->mDSSData.piyaw == pIp_mDSSData_piyaw && pIp->mDSSData.flgSP == pIp_mDSSData_flgSP && pIp->mFWarning.CWsp == pIp_mFWarning_CWsp && pIp->mFWarning.CWtf == pIp_mFWarning_CWtf && pIp->mFWarning.Wsp == pIp_mFWarning_Wsp && pIp->mFWarning.Wtf == pIp_mFWarning_Wtf && pIp->mFWarning.Wav == pIp_mFWarning_Wav && pIp->mFWarning.flgups == pIp_mFWarning_flgups && pIp->mFWarning.flgModeChange == pIp_mFWarning_flgModeChange && pIp->mFWarning.countAV == pIp_mFWarning_countAV && pIp->mFWarning.countSPLost == pIp_mFWarning_countSPLost && pIp->mFWarning.countSPSeen == pIp_mFWarning_countSPSeen && pIp->mFWarning.countSPset == pIp_mFWarning_countSPset && pIp->mFWarning.countUPSpc == pIp_mFWarning_countUPSpc
Ensure (pIp_mFWarning_countSPLost > 33750 && pIp_mFWarning_countSPSeen + 1 <= 2 && pIp_mFWarning_countSPLost != 0 && pIp_mDSSData_flgSP != 0 && (pIp->mDSSData.stateFlag_A == pIp_mDSSData_stateFlag_A) * (pIp->mDSSData.stateFlag_B == pIp_mDSSData_stateFlag_B) * (pIp->mDSSData.royaw == pIp_mDSSData_royaw) * (pIp->mDSSData.piyaw == pIp_mDSSData_piyaw) * (pIp->mDSSData.flgSP == pIp_mDSSData_flgSP) * (pIp->mFWarning.CWsp == pIp_mFWarning_CWsp) * (pIp->mFWarning.CWtf == pIp_mFWarning_CWtf) * (pIp->mFWarning.Wsp == 235) * (pIp->mFWarning.Wtf == pIp_mFWarning_Wtf) * (pIp->mFWarning.Wav == pIp_mFWarning_Wav) * (pIp->mFWarning.flgups == pIp_mFWarning_flgups) * (pIp->mFWarning.flgModeChange == pIp_mFWarning_flgModeChange) * (pIp->mFWarning.countAV == pIp_mFWarning_countAV) * (pIp->mFWarning.countSPLost == 0) * (pIp->mFWarning.countSPSeen == pIp_mFWarning_countSPSeen + 1) * (pIp->mFWarning.countSPset == 0) * (pIp->mFWarning.countUPSpc == pIp_mFWarning_countUPSpc)) || (pIp_mFWarning_countSPLost + 1 > 33750 && pIp_mDSSData_flgSP == 0 && (pIp->mDSSData.stateFlag_A == pIp_mDSSData_stateFlag_A) * (pIp->mDSSData.stateFlag_B == pIp_mDSSData_stateFlag_B) * (pIp->mDSSData.royaw == pIp_mDSSData_royaw) * (pIp->mDSSData.piyaw == pIp_mDSSData_piyaw) * (pIp->mDSSData.flgSP == pIp_mDSSData_flgSP) * (pIp->mFWarning.CWsp == pIp_mFWarning_CWsp) * (pIp->mFWarning.CWtf == pIp_mFWarning_CWtf) * (pIp->mFWarning.Wsp == 235) * (pIp->mFWarning.Wtf == pIp_mFWarning_Wtf) * (pIp->mFWarning.Wav == pIp_mFWarning_Wav) * (pIp->mFWarning.flgups == pIp_mFWarning_flgups) * (pIp->mFWarning.flgModeChange == pIp_mFWarning_flgModeChange) * (pIp->mFWarning.countAV == pIp_mFWarning_countAV) * (pIp->mFWarning.countSPLost == 0) * (pIp->mFWarning.countSPSeen == 0) * (pIp->mFWarning.countSPset == 0) * (pIp->mFWarning.countUPSpc == pIp_mFWarning_countUPSpc)) || (pIp_mFWarning_countSPLost + 1 <= 33750 && pIp_mDSSData_flgSP == 0 && (pIp->mDSSData.stateFlag_A == pIp_mDSSData_stateFlag_A) * (pIp->mDSSData.stateFlag_B == pIp_mDSSData_stateFlag_B) * (pIp->mDSSData.royaw == pIp_mDSSData_royaw) * (pIp->mDSSData.piyaw == pIp_mDSSData_piyaw) * (pIp->mDSSData.flgSP == pIp_mDSSData_flgSP) * (pIp->mFWarning.CWsp == pIp_mFWarning_CWsp) * (pIp->mFWarning.CWtf == pIp_mFWarning_CWtf) * (pIp->mFWarning.Wsp == pIp_mFWarning_Wsp) * (pIp->mFWarning.Wtf == pIp_mFWarning_Wtf) * (pIp->mFWarning.Wav == pIp_mFWarning_Wav) * (pIp->mFWarning.flgups == pIp_mFWarning_flgups) * (pIp->mFWarning.flgModeChange == pIp_mFWarning_flgModeChange) * (pIp->mFWarning.countAV == pIp_mFWarning_countAV) * (pIp->mFWarning.countSPLost == pIp_mFWarning_countSPLost + 1) * (pIp->mFWarning.countSPSeen == 0) * (pIp->mFWarning.countSPset == pIp_mFWarning_countSPset) * (pIp->mFWarning.countUPSpc == pIp_mFWarning_countUPSpc)) || (0 <= 33750 && pIp_mFWarning_countSPSeen + 1 > 2 && pIp_mFWarning_countSPLost != 0 && pIp_mDSSData_flgSP != 0 && (pIp->mDSSData.stateFlag_A == pIp_mDSSData_stateFlag_A) * (pIp->mDSSData.stateFlag_B == pIp_mDSSData_stateFlag_B) * (pIp->mDSSData.royaw == pIp_mDSSData_royaw) * (pIp->mDSSData.piyaw == pIp_mDSSData_piyaw) * (pIp->mDSSData.flgSP == pIp_mDSSData_flgSP) * (pIp->mFWarning.CWsp == pIp_mFWarning_CWsp) * (pIp->mFWarning.CWtf == pIp_mFWarning_CWtf) * (pIp->mFWarning.Wsp == pIp_mFWarning_Wsp) * (pIp->mFWarning.Wtf == pIp_mFWarning_Wtf) * (pIp->mFWarning.Wav == pIp_mFWarning_Wav) * (pIp->mFWarning.flgups == pIp_mFWarning_flgups) * (pIp->mFWarning.flgModeChange == pIp_mFWarning_flgModeChange) * (pIp->mFWarning.countAV == pIp_mFWarning_countAV) * (pIp->mFWarning.countSPLost == 0) * (pIp->mFWarning.countSPSeen == 0) * (pIp->mFWarning.countSPset == pIp_mFWarning_countSPset) * (pIp->mFWarning.countUPSpc == pIp_mFWarning_countUPSpc)) || (0 <= 33750 && pIp_mFWarning_countSPSeen > 2 && pIp_mFWarning_countSPLost == 0 && pIp_mDSSData_flgSP != 0 && (pIp->mDSSData.stateFlag_A == pIp_mDSSData_stateFlag_A) * (pIp->mDSSData.stateFlag_B == pIp_mDSSData_stateFlag_B) * (pIp->mDSSData.royaw == pIp_mDSSData_royaw) * (pIp->mDSSData.piyaw == pIp_mDSSData_piyaw) * (pIp->mDSSData.flgSP == pIp_mDSSData_flgSP) * (pIp->mFWarning.CWsp == pIp_mFWarning_CWsp) * (pIp->mFWarning.CWtf == pIp_mFWarning_CWtf) * (pIp->mFWarning.Wsp == pIp_mFWarning_Wsp) * (pIp->mFWarning.Wtf == pIp_mFWarning_Wtf) * (pIp->mFWarning.Wav == pIp_mFWarning_Wav) * (pIp->mFWarning.flgups == pIp_mFWarning_flgups) * (pIp->mFWarning.flgModeChange == pIp_mFWarning_flgModeChange) * (pIp->mFWarning.countAV == pIp_mFWarning_countAV) * (pIp->mFWarning.countSPLost == 0) * (pIp->mFWarning.countSPSeen == 0) * (pIp->mFWarning.countSPset == pIp_mFWarning_countSPset) * (pIp->mFWarning.countUPSpc == pIp_mFWarning_countUPSpc)) || (pIp_mFWarning_countSPLost <= 33750 && pIp_mFWarning_countSPSeen + 1 <= 2 && pIp_mFWarning_countSPLost != 0 && pIp_mDSSData_flgSP != 0 && (pIp->mDSSData.stateFlag_A == pIp_mDSSData_stateFlag_A) * (pIp->mDSSData.stateFlag_B == pIp_mDSSData_stateFlag_B) * (pIp->mDSSData.royaw == pIp_mDSSData_royaw) * (pIp->mDSSData.piyaw == pIp_mDSSData_piyaw) * (pIp->mDSSData.flgSP == pIp_mDSSData_flgSP) * (pIp->mFWarning.CWsp == pIp_mFWarning_CWsp) * (pIp->mFWarning.CWtf == pIp_mFWarning_CWtf) * (pIp->mFWarning.Wsp == pIp_mFWarning_Wsp) * (pIp->mFWarning.Wtf == pIp_mFWarning_Wtf) * (pIp->mFWarning.Wav == pIp_mFWarning_Wav) * (pIp->mFWarning.flgups == pIp_mFWarning_flgups) * (pIp->mFWarning.flgModeChange == pIp_mFWarning_flgModeChange) * (pIp->mFWarning.countAV == pIp_mFWarning_countAV) * (pIp->mFWarning.countSPLost == pIp_mFWarning_countSPLost) * (pIp->mFWarning.countSPSeen == pIp_mFWarning_countSPSeen + 1) * (pIp->mFWarning.countSPset == pIp_mFWarning_countSPset) * (pIp->mFWarning.countUPSpc == pIp_mFWarning_countUPSpc)) || (pIp_mFWarning_countSPLost <= 33750 && pIp_mFWarning_countSPSeen <= 2 && pIp_mFWarning_countSPLost == 0 && pIp_mDSSData_flgSP != 0 && (pIp->mDSSData.stateFlag_A == pIp_mDSSData_stateFlag_A) * (pIp->mDSSData.stateFlag_B == pIp_mDSSData_stateFlag_B) * (pIp->mDSSData.royaw == pIp_mDSSData_royaw) * (pIp->mDSSData.piyaw == pIp_mDSSData_piyaw) * (pIp->mDSSData.flgSP == pIp_mDSSData_flgSP) * (pIp->mFWarning.CWsp == pIp_mFWarning_CWsp) * (pIp->mFWarning.CWtf == pIp_mFWarning_CWtf) * (pIp->mFWarning.Wsp == pIp_mFWarning_Wsp) * (pIp->mFWarning.Wtf == pIp_mFWarning_Wtf) * (pIp->mFWarning.Wav == pIp_mFWarning_Wav) * (pIp->mFWarning.flgups == pIp_mFWarning_flgups) * (pIp->mFWarning.flgModeChange == pIp_mFWarning_flgModeChange) * (pIp->mFWarning.countAV == pIp_mFWarning_countAV) * (pIp->mFWarning.countSPLost == pIp_mFWarning_countSPLost) * (pIp->mFWarning.countSPSeen == pIp_mFWarning_countSPSeen) * (pIp->mFWarning.countSPset == pIp_mFWarning_countSPset) * (pIp->mFWarning.countUPSpc == pIp_mFWarning_countUPSpc))
*/
{

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