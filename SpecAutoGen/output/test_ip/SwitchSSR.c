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

/*@
 requires \valid(pIp) && \valid(pIp->pSDS) && \valid(pIp->pCtrl0) && \valid(pIp->pCtrl1) && \valid(pIp->pCtrl2) ;
 requires \separated(pIp,pIp->pSDS,pIp->pCtrl0,pIp->pCtrl1,pIp->pCtrl2) ;

ensures \old(pIp->mDSSData.stateFlag_A) != 0 && \old(pIp->mDSSData.stateFlag_A) == 1 ==> pIp->pSDS->stateFlag_A == \old(pIp->pSDS->stateFlag_A)&&pIp->pSDS->stateFlag_B == \old(pIp->pSDS->stateFlag_B)&&pIp->pSDS->royaw == \old(pIp->pSDS->royaw)&&pIp->pSDS->piyaw == \old(pIp->pSDS->piyaw)&&pIp->pSDS->flgSP == \old(pIp->pSDS->flgSP)&&pIp->countPublic == \old(pIp->countPublic)&&pIp->countMode == \old(pIp->countMode)&&pIp->flgMode == \old(pIp->flgMode)&&pIp->mDSSData.stateFlag_A == \old(pIp->mDSSData.stateFlag_A)&&pIp->mDSSData.stateFlag_B == \old(pIp->mDSSData.stateFlag_B)&&pIp->mDSSData.royaw == \old(pIp->mDSSData.royaw)&&pIp->mDSSData.piyaw == \old(pIp->mDSSData.piyaw)&&pIp->mDSSData.flgSP == \old(pIp->mDSSData.flgSP)&&pIp->pCtrl0->Up == \old(pIp->pCtrl0->Up)&&pIp->pCtrl0->Ud == \old(pIp->pCtrl0->Ud)&&pIp->pCtrl0->fy == \old(pIp->pCtrl0->fy)&&pIp->pCtrl1->Up == \old(pIp->pCtrl1->Up)&&pIp->pCtrl1->Ud == \old(pIp->pCtrl1->Ud)&&pIp->pCtrl1->fy == \old(pIp->pCtrl1->fy)&&pIp->pCtrl2->Up == \old(pIp->pCtrl2->Up)&&pIp->pCtrl2->Ud == \old(pIp->pCtrl2->Ud)&&pIp->pCtrl2->fy == \old(pIp->pCtrl2->fy)&&pIp->flgPRSAM == \old(pIp->flgPRSAM)&&pIp->mFWarning.CWsp == \old(pIp->mFWarning.CWsp)&&pIp->mFWarning.CWtf == \old(pIp->mFWarning.CWtf)&&pIp->mFWarning.Wsp == \old(pIp->mFWarning.Wsp)&&pIp->mFWarning.Wtf == \old(pIp->mFWarning.Wtf)&&pIp->mFWarning.Wav == \old(pIp->mFWarning.Wav)&&pIp->mFWarning.flgups == \old(pIp->mFWarning.flgups)&&pIp->mFWarning.flgModeChange == \old(pIp->mFWarning.flgModeChange)&&pIp->mFWarning.countAV == \old(pIp->mFWarning.countAV)&&pIp->mFWarning.countSPLost == \old(pIp->mFWarning.countSPLost)&&pIp->mFWarning.countSPSeen == \old(pIp->mFWarning.countSPSeen)&&pIp->mFWarning.countSPset == \old(pIp->mFWarning.countSPset)&&pIp->mFWarning.countUPSpc == \old(pIp->mFWarning.countUPSpc);

ensures \old(pIp->mDSSData.stateFlag_A) != 1 && \old(pIp->mDSSData.stateFlag_A) != 1 ==> pIp->pSDS->stateFlag_A == \old(pIp->pSDS->stateFlag_A)&&pIp->pSDS->stateFlag_B == \old(pIp->pSDS->stateFlag_B)&&pIp->pSDS->royaw == \old(pIp->pSDS->royaw)&&pIp->pSDS->piyaw == \old(pIp->pSDS->piyaw)&&pIp->pSDS->flgSP == \old(pIp->pSDS->flgSP)&&pIp->countPublic == \old(pIp->countPublic)&&pIp->countMode == \old(pIp->countMode)&&pIp->flgMode == \old(pIp->flgMode)&&pIp->mDSSData.stateFlag_A == \old(pIp->mDSSData.stateFlag_A)&&pIp->mDSSData.stateFlag_B == \old(pIp->mDSSData.stateFlag_B)&&pIp->mDSSData.royaw == \old(pIp->mDSSData.royaw)&&pIp->mDSSData.piyaw == \old(pIp->mDSSData.piyaw)&&pIp->mDSSData.flgSP == \old(pIp->mDSSData.flgSP)&&pIp->pCtrl0->Up == \old(pIp->pCtrl0->Up)&&pIp->pCtrl0->Ud == \old(pIp->pCtrl0->Ud)&&pIp->pCtrl0->fy == \old(pIp->pCtrl0->fy)&&pIp->pCtrl1->Up == \old(pIp->pCtrl1->Up)&&pIp->pCtrl1->Ud == \old(pIp->pCtrl1->Ud)&&pIp->pCtrl1->fy == \old(pIp->pCtrl1->fy)&&pIp->pCtrl2->Up == \old(pIp->pCtrl2->Up)&&pIp->pCtrl2->Ud == \old(pIp->pCtrl2->Ud)&&pIp->pCtrl2->fy == \old(pIp->pCtrl2->fy)&&pIp->flgPRSAM == \old(pIp->flgPRSAM)&&pIp->mFWarning.CWsp == \old(pIp->mFWarning.CWsp)&&pIp->mFWarning.CWtf == \old(pIp->mFWarning.CWtf)&&pIp->mFWarning.Wsp == \old(pIp->mFWarning.Wsp)&&pIp->mFWarning.Wtf == \old(pIp->mFWarning.Wtf)&&pIp->mFWarning.Wav == \old(pIp->mFWarning.Wav)&&pIp->mFWarning.flgups == \old(pIp->mFWarning.flgups)&&pIp->mFWarning.flgModeChange == \old(pIp->mFWarning.flgModeChange)&&pIp->mFWarning.countAV == \old(pIp->mFWarning.countAV)&&pIp->mFWarning.countSPLost == \old(pIp->mFWarning.countSPLost)&&pIp->mFWarning.countSPSeen == \old(pIp->mFWarning.countSPSeen)&&pIp->mFWarning.countSPset == \old(pIp->mFWarning.countSPset)&&pIp->mFWarning.countUPSpc == \old(pIp->mFWarning.countUPSpc);

*/

void SwitchSSR(SAMSubModeRoll *pIp)

{

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