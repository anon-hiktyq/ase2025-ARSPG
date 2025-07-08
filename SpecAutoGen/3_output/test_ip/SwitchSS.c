
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

typedef struct __SoftFaultProceedSP
{

	SDSSData		mDSSData;
	SFWarning		mFWarning;
	SController     mController;
	int				countPublic;
	int				countMode;

} SoftFaultProceedSP;



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


void SoftFaultProceedSPFun(SoftFaultProceedSP *pIp)
{

	pIp -> mFWarning.countSPset++ ;


	if(pIp -> mFWarning.countSPset == 5){

		 	SwitchSS(pIp);
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