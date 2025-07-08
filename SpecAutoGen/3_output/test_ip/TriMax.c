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

typedef struct TAG_CONTROLLER
{
	int Up;
	int Up_last;
}SController;


typedef struct __FaultJudgeProceed
{
/* 输入端口 */
	/* 输出端口 */
	int			nouse;
	int			countPublic;
	int			countMode;
	SAttitude			mAttitude;
	SDSSData			mDSSData;
	SController 		mController0;
    SController         mController1;
    SController         mController2;
	/* 输入输出端口 */
	SFWarning			mFWarning;
	/* 状态变量 */
	/* 参数变量 */
} FaultJudgeProceed;

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


void SoftFaultJudgeSP(FaultJudgeProceed *pIp)

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

void SoftFaultProceed(FaultJudgeProceed *pIp)
{

	pIp -> mFWarning.countSPset++ ;


	if(pIp -> mFWarning.countSPset == 5){

		 	SwitchSSS(pIp);
	}else if(pIp -> mFWarning.countSPset == 10){

			pIp -> mFWarning.CWsp = 0 ;
			pIp -> mFWarning.CWtf = 0 ;
			pIp -> mFWarning.countSPset = 0 ;
			pIp -> mFWarning.Wsp = 0 ;
	        pIp -> mController.Up = 0 ;
	        pIp -> countMode = 0 ;
	        pIp -> countPublic = 0 ;
	}
	   

	return ;
}

void TriMax(FaultJudgeProceed *pIp){
    int fx1 = pIp->mAttitude.angle[0];
    int fy2 = pIp->mAttitude.angle[1];
    int fz3 = pIp->mAttitude.angle[2];

    if (fx1 > fy2)
    {
        pIp->max = fx1;
    }
    else
    {
        pIp->max = fy2;
    }
    
    if (fz3 > pIp->max)
    {
        pIp->max = fz3;
    }
    
}




void NoctrlJudge(FaultJudgeProceed *pIp)
{   

    TriMax(pIp);
    
    if (pIp->max > 2)
    {
        pIp->mFWarning.countAV++;
      
        if (pIp->mFWarning.countAV > 300)
        {
            pIp->mFWarning.Wav = 1;
         
        }
    }
    else if (pIp->mFWarning.countAV > 0)
    {
        pIp->mFWarning.countAV--;
      
    }
    else
    {
        pIp->nouse = pIp->nouse;
      
    }

    return;
}



void FaultJudgeProceedFun(FaultJudgeProceed *pIp)
{

	if ((pIp -> mFWarning.CWsp == 1) && (pIp -> mFWarning.Wsp == 0))
    {

        SoftFaultJudgeSP(pIp);

    }

    if ((pIp -> mFWarning.CWsp == 1) && (pIp -> mFWarning.Wsp == 1))
    {

    	SoftFaultProceed(pIp);
    	

    }

        NoctrlJudge(pIp);

	return ;
}