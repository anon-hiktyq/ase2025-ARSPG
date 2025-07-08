

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