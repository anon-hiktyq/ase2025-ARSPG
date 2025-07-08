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

/*@
 requires \valid(pIp) && \valid(pIp->mAttitude.angle+ (0..3)) && \valid(pIp->mAttitude.rate+ (0..3)) ;
 requires \separated(pIp,pIp->mAttitude.angle+(0..3),pIp->mAttitude.rate+(0..3)) ;

ensures \old(pIp->mDSSData.stateFlag_A) == 1 && pIp->mAttitude.angle[0] == \old(pIp->mAttitude.angle[0]) && pIp->mAttitude.angle[1] == \old(pIp->mAttitude.angle[1]) && pIp->mAttitude.angle[2] == \old(pIp->mAttitude.angle[2]) && pIp->mAttitude.rate[0] == \old(pIp->mAttitude.rate[0]) && pIp->mAttitude.rate[1] == \old(pIp->mAttitude.rate[1]) && pIp->mAttitude.rate[2] == \old(pIp->mAttitude.rate[2]) ==> pIp->nouse == \old(pIp->nouse)&&pIp->countPublic == \old(pIp->countPublic)&&pIp->countMode == \old(pIp->countMode)&&pIp->mDSSData.stateFlag_A == 0&&pIp->mDSSData.stateFlag_B == \old(pIp->mDSSData.stateFlag_B)&&pIp->mDSSData.royaw == \old(pIp->mDSSData.royaw)&&pIp->mDSSData.piyaw == \old(pIp->mDSSData.piyaw)&&pIp->mDSSData.flgSP == \old(pIp->mDSSData.flgSP)&&pIp->mController.Up == \old(pIp->mController.Up)&&pIp->mController.Ud == \old(pIp->mController.Ud)&&pIp->mController.fy == \old(pIp->mController.fy)&&pIp->mFWarning.CWsp == \old(pIp->mFWarning.CWsp)&&pIp->mFWarning.CWtf == \old(pIp->mFWarning.CWtf)&&pIp->mFWarning.Wsp == \old(pIp->mFWarning.Wsp)&&pIp->mFWarning.Wtf == \old(pIp->mFWarning.Wtf)&&pIp->mFWarning.Wav == \old(pIp->mFWarning.Wav)&&pIp->mFWarning.flgups == \old(pIp->mFWarning.flgups)&&pIp->mFWarning.flgModeChange == \old(pIp->mFWarning.flgModeChange)&&pIp->mFWarning.countAV == \old(pIp->mFWarning.countAV)&&pIp->mFWarning.countSPLost == \old(pIp->mFWarning.countSPLost)&&pIp->mFWarning.countSPSeen == \old(pIp->mFWarning.countSPSeen)&&pIp->mFWarning.countSPset == \old(pIp->mFWarning.countSPset)&&pIp->mFWarning.countUPSpc == \old(pIp->mFWarning.countUPSpc);

ensures \old(pIp->mDSSData.stateFlag_A) != 1 && pIp->mAttitude.angle[0] == \old(pIp->mAttitude.angle[0]) && pIp->mAttitude.angle[1] == \old(pIp->mAttitude.angle[1]) && pIp->mAttitude.angle[2] == \old(pIp->mAttitude.angle[2]) && pIp->mAttitude.rate[0] == \old(pIp->mAttitude.rate[0]) && pIp->mAttitude.rate[1] == \old(pIp->mAttitude.rate[1]) && pIp->mAttitude.rate[2] == \old(pIp->mAttitude.rate[2]) ==> pIp->nouse == \old(pIp->nouse)&&pIp->countPublic == \old(pIp->countPublic)&&pIp->countMode == \old(pIp->countMode)&&pIp->mDSSData.stateFlag_A == 1&&pIp->mDSSData.stateFlag_B == \old(pIp->mDSSData.stateFlag_B)&&pIp->mDSSData.royaw == \old(pIp->mDSSData.royaw)&&pIp->mDSSData.piyaw == \old(pIp->mDSSData.piyaw)&&pIp->mDSSData.flgSP == \old(pIp->mDSSData.flgSP)&&pIp->mController.Up == \old(pIp->mController.Up)&&pIp->mController.Ud == \old(pIp->mController.Ud)&&pIp->mController.fy == \old(pIp->mController.fy)&&pIp->mFWarning.CWsp == \old(pIp->mFWarning.CWsp)&&pIp->mFWarning.CWtf == \old(pIp->mFWarning.CWtf)&&pIp->mFWarning.Wsp == \old(pIp->mFWarning.Wsp)&&pIp->mFWarning.Wtf == \old(pIp->mFWarning.Wtf)&&pIp->mFWarning.Wav == \old(pIp->mFWarning.Wav)&&pIp->mFWarning.flgups == \old(pIp->mFWarning.flgups)&&pIp->mFWarning.flgModeChange == \old(pIp->mFWarning.flgModeChange)&&pIp->mFWarning.countAV == \old(pIp->mFWarning.countAV)&&pIp->mFWarning.countSPLost == \old(pIp->mFWarning.countSPLost)&&pIp->mFWarning.countSPSeen == \old(pIp->mFWarning.countSPSeen)&&pIp->mFWarning.countSPset == \old(pIp->mFWarning.countSPset)&&pIp->mFWarning.countUPSpc == \old(pIp->mFWarning.countUPSpc);

*/

void SwitchSSS(FaultJudgeProceed *pIp)

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