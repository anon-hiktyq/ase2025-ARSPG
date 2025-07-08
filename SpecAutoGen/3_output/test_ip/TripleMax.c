
typedef struct TAG_ATTITUDE_PARA     	
{                                    	
	                                 	
	int 	angle[3];			 
	int 	rate[3]; 			 
	                                 	
}SAttitude;

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



typedef struct __NoctrlJudge
{
/* 输入端口 */
	SAttitude			mAttitude;
	/* 输出端口 */
	/* 输入输出端口 */
	int       			nouse;
    int                 max;
	SFWarning			mFWarning;

	/* 状态变量 */
	/* 参数变量 */
} NoctrlJudge;


void TripleMax(NoctrlJudge *pIp){
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




void NoctrlJudgeFun(NoctrlJudge *pIp)
{   

    TripleMax(pIp);
    
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
