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
typedef struct __SAMSubModePitch
{
/* 输入端口 */
	const SDSSData*			pSDS;
	int		countPublic;
	int		countMode;
	int         flgMode;
	/* 输出端口 */
	/* 输入输出端口 */
	SController*	pCtrl0;
	SController*	pCtrl1;
	SController*	pCtrl2;
	/* 状态变量 */
	/* 参数变量 */
} SAMSubModePitch;

/*@
 requires \valid(pIp) && \valid(pIp->pSDS) && \valid(pIp->pCtrl0) && \valid(pIp->pCtrl1) && \valid(pIp->pCtrl2) ;
 requires \separated(pIp,pIp->pSDS,pIp->pCtrl0,pIp->pCtrl1,pIp->pCtrl2) ;

ensures \old(pIp->countMode) > 5625 && \old(pIp->pSDS->flgSP) != 1 ==> pIp->pSDS->stateFlag_A == \old(pIp->pSDS->stateFlag_A)&&pIp->pSDS->stateFlag_B == \old(pIp->pSDS->stateFlag_B)&&pIp->pSDS->royaw == \old(pIp->pSDS->royaw)&&pIp->pSDS->piyaw == \old(pIp->pSDS->piyaw)&&pIp->pSDS->flgSP == \old(pIp->pSDS->flgSP)&&pIp->countPublic == 0&&pIp->countMode == 0&&pIp->flgMode == 34&&pIp->pCtrl0->Up == \old(pIp->pCtrl0->Up)&&pIp->pCtrl0->Ud == \old(pIp->pCtrl0->Ud)&&pIp->pCtrl0->fy == \old(pIp->pCtrl0->fy)&&pIp->pCtrl1->Up == \old(pIp->pCtrl1->Up)&&pIp->pCtrl1->Ud == \old(pIp->pCtrl1->Ud)&&pIp->pCtrl1->fy == \old(pIp->pCtrl1->fy)&&pIp->pCtrl2->Up == \old(pIp->pCtrl2->Up)&&pIp->pCtrl2->Ud == \old(pIp->pCtrl2->Ud)&&pIp->pCtrl2->fy == \old(pIp->pCtrl2->fy);

ensures \old(pIp->countMode) > 5625 && \old(pIp->pSDS->piyaw) >= -1 && \old(pIp->pSDS->piyaw) <= 1 && \old(pIp->pSDS->flgSP) == 1 ==> pIp->pSDS->stateFlag_A == \old(pIp->pSDS->stateFlag_A)&&pIp->pSDS->stateFlag_B == \old(pIp->pSDS->stateFlag_B)&&pIp->pSDS->royaw == \old(pIp->pSDS->royaw)&&pIp->pSDS->piyaw == \old(pIp->pSDS->piyaw)&&pIp->pSDS->flgSP == \old(pIp->pSDS->flgSP)&&pIp->countPublic == 0&&pIp->countMode == 0&&pIp->flgMode == 34&&pIp->pCtrl0->Up == \old(pIp->pCtrl0->Up)&&pIp->pCtrl0->Ud == \old(pIp->pCtrl0->Ud)&&pIp->pCtrl0->fy == \old(pIp->pCtrl0->fy)&&pIp->pCtrl1->Up == \old(pIp->pCtrl1->Up)&&pIp->pCtrl1->Ud == \old(pIp->pCtrl1->Ud)&&pIp->pCtrl1->fy == \old(pIp->pCtrl1->fy)&&pIp->pCtrl2->Up == \old(pIp->pCtrl2->Up)&&pIp->pCtrl2->Ud == \old(pIp->pCtrl2->Ud)&&pIp->pCtrl2->fy == \old(pIp->pCtrl2->fy);

ensures \old(pIp->countMode) > 5625 && \old(pIp->countPublic) + 1 <= 16 && \old(pIp->pSDS->piyaw) < -1 && \old(pIp->pSDS->piyaw) <= 1 && \old(pIp->pSDS->flgSP) == 1 ==> pIp->pSDS->stateFlag_A == \old(pIp->pSDS->stateFlag_A)&&pIp->pSDS->stateFlag_B == \old(pIp->pSDS->stateFlag_B)&&pIp->pSDS->royaw == \old(pIp->pSDS->royaw)&&pIp->pSDS->piyaw == \old(pIp->pSDS->piyaw)&&pIp->pSDS->flgSP == \old(pIp->pSDS->flgSP)&&pIp->countPublic == 0&&pIp->countMode == 0&&pIp->flgMode == 34&&pIp->pCtrl0->Up == 0&&pIp->pCtrl0->Ud == \old(pIp->pCtrl0->Ud)&&pIp->pCtrl0->fy == \old(pIp->pCtrl0->fy)&&pIp->pCtrl1->Up == 0&&pIp->pCtrl1->Ud == \old(pIp->pCtrl1->Ud)&&pIp->pCtrl1->fy == \old(pIp->pCtrl1->fy)&&pIp->pCtrl2->Up == 0&&pIp->pCtrl2->Ud == \old(pIp->pCtrl2->Ud)&&pIp->pCtrl2->fy == \old(pIp->pCtrl2->fy);

ensures \old(pIp->countMode) > 5625 && \old(pIp->countPublic) + 1 <= 16 && \old(pIp->pSDS->piyaw) > 1 && \old(pIp->pSDS->flgSP) == 1 ==> pIp->pSDS->stateFlag_A == \old(pIp->pSDS->stateFlag_A)&&pIp->pSDS->stateFlag_B == \old(pIp->pSDS->stateFlag_B)&&pIp->pSDS->royaw == \old(pIp->pSDS->royaw)&&pIp->pSDS->piyaw == \old(pIp->pSDS->piyaw)&&pIp->pSDS->flgSP == \old(pIp->pSDS->flgSP)&&pIp->countPublic == 0&&pIp->countMode == 0&&pIp->flgMode == 34&&pIp->pCtrl0->Up == 0&&pIp->pCtrl0->Ud == \old(pIp->pCtrl0->Ud)&&pIp->pCtrl0->fy == \old(pIp->pCtrl0->fy)&&pIp->pCtrl1->Up == 0&&pIp->pCtrl1->Ud == \old(pIp->pCtrl1->Ud)&&pIp->pCtrl1->fy == \old(pIp->pCtrl1->fy)&&pIp->pCtrl2->Up == 0&&pIp->pCtrl2->Ud == \old(pIp->pCtrl2->Ud)&&pIp->pCtrl2->fy == \old(pIp->pCtrl2->fy);

ensures 0 <= 5625 && \old(pIp->countPublic) + 1 > 16 && \old(pIp->pSDS->piyaw) > 1 && \old(pIp->pSDS->flgSP) == 1 ==> pIp->pSDS->stateFlag_A == \old(pIp->pSDS->stateFlag_A)&&pIp->pSDS->stateFlag_B == \old(pIp->pSDS->stateFlag_B)&&pIp->pSDS->royaw == \old(pIp->pSDS->royaw)&&pIp->pSDS->piyaw == \old(pIp->pSDS->piyaw)&&pIp->pSDS->flgSP == \old(pIp->pSDS->flgSP)&&pIp->countPublic == 0&&pIp->countMode == 0&&pIp->flgMode == 51&&pIp->pCtrl0->Up == \old(pIp->pCtrl0->Up)&&pIp->pCtrl0->Ud == \old(pIp->pCtrl0->Ud)&&pIp->pCtrl0->fy == \old(pIp->pCtrl0->fy)&&pIp->pCtrl1->Up == \old(pIp->pCtrl1->Up)&&pIp->pCtrl1->Ud == \old(pIp->pCtrl1->Ud)&&pIp->pCtrl1->fy == \old(pIp->pCtrl1->fy)&&pIp->pCtrl2->Up == \old(pIp->pCtrl2->Up)&&pIp->pCtrl2->Ud == \old(pIp->pCtrl2->Ud)&&pIp->pCtrl2->fy == \old(pIp->pCtrl2->fy);

ensures 0 <= 5625 && \old(pIp->countPublic) + 1 > 16 && \old(pIp->pSDS->piyaw) < -1 && \old(pIp->pSDS->piyaw) <= 1 && \old(pIp->pSDS->flgSP) == 1 ==> pIp->pSDS->stateFlag_A == \old(pIp->pSDS->stateFlag_A)&&pIp->pSDS->stateFlag_B == \old(pIp->pSDS->stateFlag_B)&&pIp->pSDS->royaw == \old(pIp->pSDS->royaw)&&pIp->pSDS->piyaw == \old(pIp->pSDS->piyaw)&&pIp->pSDS->flgSP == \old(pIp->pSDS->flgSP)&&pIp->countPublic == 0&&pIp->countMode == 0&&pIp->flgMode == 51&&pIp->pCtrl0->Up == \old(pIp->pCtrl0->Up)&&pIp->pCtrl0->Ud == \old(pIp->pCtrl0->Ud)&&pIp->pCtrl0->fy == \old(pIp->pCtrl0->fy)&&pIp->pCtrl1->Up == \old(pIp->pCtrl1->Up)&&pIp->pCtrl1->Ud == \old(pIp->pCtrl1->Ud)&&pIp->pCtrl1->fy == \old(pIp->pCtrl1->fy)&&pIp->pCtrl2->Up == \old(pIp->pCtrl2->Up)&&pIp->pCtrl2->Ud == \old(pIp->pCtrl2->Ud)&&pIp->pCtrl2->fy == \old(pIp->pCtrl2->fy);

ensures \old(pIp->countMode) <= 5625 && \old(pIp->countPublic) + 1 <= 16 && \old(pIp->pSDS->piyaw) > 1 && \old(pIp->pSDS->flgSP) == 1 ==> pIp->pSDS->stateFlag_A == \old(pIp->pSDS->stateFlag_A)&&pIp->pSDS->stateFlag_B == \old(pIp->pSDS->stateFlag_B)&&pIp->pSDS->royaw == \old(pIp->pSDS->royaw)&&pIp->pSDS->piyaw == \old(pIp->pSDS->piyaw)&&pIp->pSDS->flgSP == \old(pIp->pSDS->flgSP)&&pIp->countPublic == \old(pIp->countPublic) + 1&&pIp->countMode == \old(pIp->countMode)&&pIp->flgMode == \old(pIp->flgMode)&&pIp->pCtrl0->Up == 0&&pIp->pCtrl0->Ud == \old(pIp->pCtrl0->Ud)&&pIp->pCtrl0->fy == \old(pIp->pCtrl0->fy)&&pIp->pCtrl1->Up == 0&&pIp->pCtrl1->Ud == \old(pIp->pCtrl1->Ud)&&pIp->pCtrl1->fy == \old(pIp->pCtrl1->fy)&&pIp->pCtrl2->Up == 0&&pIp->pCtrl2->Ud == \old(pIp->pCtrl2->Ud)&&pIp->pCtrl2->fy == \old(pIp->pCtrl2->fy);

ensures \old(pIp->countMode) <= 5625 && \old(pIp->countPublic) + 1 <= 16 && \old(pIp->pSDS->piyaw) < -1 && \old(pIp->pSDS->piyaw) <= 1 && \old(pIp->pSDS->flgSP) == 1 ==> pIp->pSDS->stateFlag_A == \old(pIp->pSDS->stateFlag_A)&&pIp->pSDS->stateFlag_B == \old(pIp->pSDS->stateFlag_B)&&pIp->pSDS->royaw == \old(pIp->pSDS->royaw)&&pIp->pSDS->piyaw == \old(pIp->pSDS->piyaw)&&pIp->pSDS->flgSP == \old(pIp->pSDS->flgSP)&&pIp->countPublic == \old(pIp->countPublic) + 1&&pIp->countMode == \old(pIp->countMode)&&pIp->flgMode == \old(pIp->flgMode)&&pIp->pCtrl0->Up == 0&&pIp->pCtrl0->Ud == \old(pIp->pCtrl0->Ud)&&pIp->pCtrl0->fy == \old(pIp->pCtrl0->fy)&&pIp->pCtrl1->Up == 0&&pIp->pCtrl1->Ud == \old(pIp->pCtrl1->Ud)&&pIp->pCtrl1->fy == \old(pIp->pCtrl1->fy)&&pIp->pCtrl2->Up == 0&&pIp->pCtrl2->Ud == \old(pIp->pCtrl2->Ud)&&pIp->pCtrl2->fy == \old(pIp->pCtrl2->fy);

ensures \old(pIp->countMode) <= 5625 && \old(pIp->pSDS->piyaw) >= -1 && \old(pIp->pSDS->piyaw) <= 1 && \old(pIp->pSDS->flgSP) == 1 ==> pIp->pSDS->stateFlag_A == \old(pIp->pSDS->stateFlag_A)&&pIp->pSDS->stateFlag_B == \old(pIp->pSDS->stateFlag_B)&&pIp->pSDS->royaw == \old(pIp->pSDS->royaw)&&pIp->pSDS->piyaw == \old(pIp->pSDS->piyaw)&&pIp->pSDS->flgSP == \old(pIp->pSDS->flgSP)&&pIp->countPublic == \old(pIp->countPublic)&&pIp->countMode == \old(pIp->countMode)&&pIp->flgMode == \old(pIp->flgMode)&&pIp->pCtrl0->Up == \old(pIp->pCtrl0->Up)&&pIp->pCtrl0->Ud == \old(pIp->pCtrl0->Ud)&&pIp->pCtrl0->fy == \old(pIp->pCtrl0->fy)&&pIp->pCtrl1->Up == \old(pIp->pCtrl1->Up)&&pIp->pCtrl1->Ud == \old(pIp->pCtrl1->Ud)&&pIp->pCtrl1->fy == \old(pIp->pCtrl1->fy)&&pIp->pCtrl2->Up == \old(pIp->pCtrl2->Up)&&pIp->pCtrl2->Ud == \old(pIp->pCtrl2->Ud)&&pIp->pCtrl2->fy == \old(pIp->pCtrl2->fy);

ensures \old(pIp->countMode) <= 5625 && \old(pIp->pSDS->flgSP) != 1 ==> pIp->pSDS->stateFlag_A == \old(pIp->pSDS->stateFlag_A)&&pIp->pSDS->stateFlag_B == \old(pIp->pSDS->stateFlag_B)&&pIp->pSDS->royaw == \old(pIp->pSDS->royaw)&&pIp->pSDS->piyaw == \old(pIp->pSDS->piyaw)&&pIp->pSDS->flgSP == \old(pIp->pSDS->flgSP)&&pIp->countPublic == 0&&pIp->countMode == \old(pIp->countMode)&&pIp->flgMode == \old(pIp->flgMode)&&pIp->pCtrl0->Up == \old(pIp->pCtrl0->Up)&&pIp->pCtrl0->Ud == \old(pIp->pCtrl0->Ud)&&pIp->pCtrl0->fy == \old(pIp->pCtrl0->fy)&&pIp->pCtrl1->Up == \old(pIp->pCtrl1->Up)&&pIp->pCtrl1->Ud == \old(pIp->pCtrl1->Ud)&&pIp->pCtrl1->fy == \old(pIp->pCtrl1->fy)&&pIp->pCtrl2->Up == \old(pIp->pCtrl2->Up)&&pIp->pCtrl2->Ud == \old(pIp->pCtrl2->Ud)&&pIp->pCtrl2->fy == \old(pIp->pCtrl2->fy);

*/

void SAMSubModePitchFun(SAMSubModePitch *pIp)

{

    if ( pIp -> pSDS->flgSP == 1 )
    {
		

		if ( pIp -> pSDS->piyaw > 1 || pIp -> pSDS->piyaw < -1 )
		{
			pIp -> countPublic++ ;

			if ( pIp -> countPublic > 16 )
			{
				

				pIp->flgMode = 0x33 ;
				pIp -> countMode = 0 ;
				pIp -> countPublic = 0 ;
			}
			else
			{
				pIp -> pCtrl0->Up = 0 ;
				pIp -> pCtrl1->Up = 0 ;
				pIp -> pCtrl2->Up = 0 ;

			}
		}
	}
    else
    {
        pIp -> countPublic = 0 ;
    }

    if (pIp -> countMode > 5625)
    {
		pIp->flgMode = 0x22 ;
        pIp -> countMode = 0 ;
        pIp -> countPublic = 0 ;

    }

	return ;
}