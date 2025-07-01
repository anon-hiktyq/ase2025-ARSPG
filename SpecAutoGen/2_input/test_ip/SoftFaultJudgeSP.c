
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



typedef struct __SoftFaultJudgeSP
{

 SDSSData mDSSData;
 SFWarning mFWarning;


} SoftFaultJudgeSP;


void SoftFaultJudgeSPFun(SoftFaultJudgeSP *pIp)

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
