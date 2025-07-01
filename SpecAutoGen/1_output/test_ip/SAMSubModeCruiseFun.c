
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
typedef struct __SAMSubModeCruise
{
	const int			countMode;
	SFWarning			mFWarning;
	int      		    Count160ms;

} SAMSubModeCruise;

void SAMSubModeCruiseFun(SAMSubModeCruise *pIp)

/*@
With pIp_countMode pIp_mFWarning_CWsp pIp_mFWarning_CWtf pIp_mFWarning_Wsp pIp_mFWarning_Wtf pIp_mFWarning_Wav pIp_mFWarning_flgups pIp_mFWarning_flgModeChange pIp_mFWarning_countAV pIp_mFWarning_countSPLost pIp_mFWarning_countSPSeen pIp_mFWarning_countSPset pIp_mFWarning_countUPSpc pIp_Count160ms
Require pIp->countMode == pIp_countMode && pIp->mFWarning.CWsp == pIp_mFWarning_CWsp && pIp->mFWarning.CWtf == pIp_mFWarning_CWtf && pIp->mFWarning.Wsp == pIp_mFWarning_Wsp && pIp->mFWarning.Wtf == pIp_mFWarning_Wtf && pIp->mFWarning.Wav == pIp_mFWarning_Wav && pIp->mFWarning.flgups == pIp_mFWarning_flgups && pIp->mFWarning.flgModeChange == pIp_mFWarning_flgModeChange && pIp->mFWarning.countAV == pIp_mFWarning_countAV && pIp->mFWarning.countSPLost == pIp_mFWarning_countSPLost && pIp->mFWarning.countSPSeen == pIp_mFWarning_countSPSeen && pIp->mFWarning.countSPset == pIp_mFWarning_countSPset && pIp->mFWarning.countUPSpc == pIp_mFWarning_countUPSpc && pIp->Count160ms == pIp_Count160ms
Ensure emp
*/{

	if (pIp -> countMode == 4000)
	{
		pIp -> mFWarning.CWsp = 1 ;
	}

	return ;
}