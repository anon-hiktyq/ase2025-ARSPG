
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

void SAMSubModePitchFun(SAMSubModePitch *pIp)

/*@
With pIp_pSDS_stateFlag_A pIp_pSDS_stateFlag_B pIp_pSDS_royaw pIp_pSDS_piyaw pIp_pSDS_flgSP pIp_countPublic pIp_countMode pIp_flgMode pIp_pCtrl0_Up pIp_pCtrl0_Ud pIp_pCtrl0_fy pIp_pCtrl1_Up pIp_pCtrl1_Ud pIp_pCtrl1_fy pIp_pCtrl2_Up pIp_pCtrl2_Ud pIp_pCtrl2_fy
Require pIp->pSDS->stateFlag_A == pIp_pSDS_stateFlag_A && pIp->pSDS->stateFlag_B == pIp_pSDS_stateFlag_B && pIp->pSDS->royaw == pIp_pSDS_royaw && pIp->pSDS->piyaw == pIp_pSDS_piyaw && pIp->pSDS->flgSP == pIp_pSDS_flgSP && pIp->countPublic == pIp_countPublic && pIp->countMode == pIp_countMode && pIp->flgMode == pIp_flgMode && pIp->pCtrl0->Up == pIp_pCtrl0_Up && pIp->pCtrl0->Ud == pIp_pCtrl0_Ud && pIp->pCtrl0->fy == pIp_pCtrl0_fy && pIp->pCtrl1->Up == pIp_pCtrl1_Up && pIp->pCtrl1->Ud == pIp_pCtrl1_Ud && pIp->pCtrl1->fy == pIp_pCtrl1_fy && pIp->pCtrl2->Up == pIp_pCtrl2_Up && pIp->pCtrl2->Ud == pIp_pCtrl2_Ud && pIp->pCtrl2->fy == pIp_pCtrl2_fy
Ensure emp
*/{

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