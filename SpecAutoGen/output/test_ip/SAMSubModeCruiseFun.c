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

/*@
 requires \valid(pIp) ;

ensures \old(pIp->countMode) == 4000 ==> pIp->countMode == \old(pIp->countMode)&&pIp->mFWarning.CWsp == 1&&pIp->mFWarning.CWtf == \old(pIp->mFWarning.CWtf)&&pIp->mFWarning.Wsp == \old(pIp->mFWarning.Wsp)&&pIp->mFWarning.Wtf == \old(pIp->mFWarning.Wtf)&&pIp->mFWarning.Wav == \old(pIp->mFWarning.Wav)&&pIp->mFWarning.flgups == \old(pIp->mFWarning.flgups)&&pIp->mFWarning.flgModeChange == \old(pIp->mFWarning.flgModeChange)&&pIp->mFWarning.countAV == \old(pIp->mFWarning.countAV)&&pIp->mFWarning.countSPLost == \old(pIp->mFWarning.countSPLost)&&pIp->mFWarning.countSPSeen == \old(pIp->mFWarning.countSPSeen)&&pIp->mFWarning.countSPset == \old(pIp->mFWarning.countSPset)&&pIp->mFWarning.countUPSpc == \old(pIp->mFWarning.countUPSpc)&&pIp->Count160ms == \old(pIp->Count160ms);

ensures \old(pIp->countMode) != 4000 ==> pIp->countMode == \old(pIp->countMode)&&pIp->mFWarning.CWsp == \old(pIp->mFWarning.CWsp)&&pIp->mFWarning.CWtf == \old(pIp->mFWarning.CWtf)&&pIp->mFWarning.Wsp == \old(pIp->mFWarning.Wsp)&&pIp->mFWarning.Wtf == \old(pIp->mFWarning.Wtf)&&pIp->mFWarning.Wav == \old(pIp->mFWarning.Wav)&&pIp->mFWarning.flgups == \old(pIp->mFWarning.flgups)&&pIp->mFWarning.flgModeChange == \old(pIp->mFWarning.flgModeChange)&&pIp->mFWarning.countAV == \old(pIp->mFWarning.countAV)&&pIp->mFWarning.countSPLost == \old(pIp->mFWarning.countSPLost)&&pIp->mFWarning.countSPSeen == \old(pIp->mFWarning.countSPSeen)&&pIp->mFWarning.countSPset == \old(pIp->mFWarning.countSPset)&&pIp->mFWarning.countUPSpc == \old(pIp->mFWarning.countUPSpc)&&pIp->Count160ms == \old(pIp->Count160ms);

*/

void SAMSubModeCruiseFun(SAMSubModeCruise *pIp)

{

	if (pIp -> countMode == 4000)
	{
		pIp -> mFWarning.CWsp = 1 ;
	}

	return ;
}