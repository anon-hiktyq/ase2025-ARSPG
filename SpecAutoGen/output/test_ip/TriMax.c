
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
	SController 		mController0;
    SController         mController1;
    SController         mController2;
	/* 输入输出端口 */
	SFWarning			mFWarning;
	/* 状态变量 */
	/* 参数变量 */
} FaultJudgeProceed;

/*@
    requires \valid(pIp);
    ensures pIp->max == \max(pIp->mAttitude.angle[0], \max(pIp->mAttitude.angle[1], pIp->mAttitude.angle[2]));
*/
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
