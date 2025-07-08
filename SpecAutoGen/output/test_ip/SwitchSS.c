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

/*@
 requires \valid(pIp) ;

ensures \old(pIp->mDSSData.stateFlag_A) == 1 ==> pIp->mDSSData.stateFlag_A == 0&&pIp->mDSSData.stateFlag_B == \old(pIp->mDSSData.stateFlag_B)&&pIp->mDSSData.royaw == \old(pIp->mDSSData.royaw)&&pIp->mDSSData.piyaw == \old(pIp->mDSSData.piyaw)&&pIp->mDSSData.flgSP == \old(pIp->mDSSData.flgSP)&&pIp->mFWarning.CWsp == \old(pIp->mFWarning.CWsp)&&pIp->mFWarning.CWtf == \old(pIp->mFWarning.CWtf)&&pIp->mFWarning.Wsp == \old(pIp->mFWarning.Wsp)&&pIp->mFWarning.Wtf == \old(pIp->mFWarning.Wtf)&&pIp->mFWarning.Wav == \old(pIp->mFWarning.Wav)&&pIp->mFWarning.flgups == \old(pIp->mFWarning.flgups)&&pIp->mFWarning.flgModeChange == \old(pIp->mFWarning.flgModeChange)&&pIp->mFWarning.countAV == \old(pIp->mFWarning.countAV)&&pIp->mFWarning.countSPLost == \old(pIp->mFWarning.countSPLost)&&pIp->mFWarning.countSPSeen == \old(pIp->mFWarning.countSPSeen)&&pIp->mFWarning.countSPset == \old(pIp->mFWarning.countSPset)&&pIp->mFWarning.countUPSpc == \old(pIp->mFWarning.countUPSpc)&&pIp->mController.Up == \old(pIp->mController.Up)&&pIp->mController.Ud == \old(pIp->mController.Ud)&&pIp->mController.fy == \old(pIp->mController.fy)&&pIp->countPublic == \old(pIp->countPublic)&&pIp->countMode == \old(pIp->countMode);

ensures \old(pIp->mDSSData.stateFlag_A) != 1 ==> pIp->mDSSData.stateFlag_A == 1&&pIp->mDSSData.stateFlag_B == \old(pIp->mDSSData.stateFlag_B)&&pIp->mDSSData.royaw == \old(pIp->mDSSData.royaw)&&pIp->mDSSData.piyaw == \old(pIp->mDSSData.piyaw)&&pIp->mDSSData.flgSP == \old(pIp->mDSSData.flgSP)&&pIp->mFWarning.CWsp == \old(pIp->mFWarning.CWsp)&&pIp->mFWarning.CWtf == \old(pIp->mFWarning.CWtf)&&pIp->mFWarning.Wsp == \old(pIp->mFWarning.Wsp)&&pIp->mFWarning.Wtf == \old(pIp->mFWarning.Wtf)&&pIp->mFWarning.Wav == \old(pIp->mFWarning.Wav)&&pIp->mFWarning.flgups == \old(pIp->mFWarning.flgups)&&pIp->mFWarning.flgModeChange == \old(pIp->mFWarning.flgModeChange)&&pIp->mFWarning.countAV == \old(pIp->mFWarning.countAV)&&pIp->mFWarning.countSPLost == \old(pIp->mFWarning.countSPLost)&&pIp->mFWarning.countSPSeen == \old(pIp->mFWarning.countSPSeen)&&pIp->mFWarning.countSPset == \old(pIp->mFWarning.countSPset)&&pIp->mFWarning.countUPSpc == \old(pIp->mFWarning.countUPSpc)&&pIp->mController.Up == \old(pIp->mController.Up)&&pIp->mController.Ud == \old(pIp->mController.Ud)&&pIp->mController.fy == \old(pIp->mController.fy)&&pIp->countPublic == \old(pIp->countPublic)&&pIp->countMode == \old(pIp->countMode);

*/

void SwitchSS(SoftFaultProceedSP *pIp)

{

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