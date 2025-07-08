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
typedef struct TAG_FALSE_RATE_MODULATOR
{
	
	int 	u;						
	int 	r;						
	int 	Yp;						
	int 	Yn;						
	                            	
}SFratemodulator;
typedef struct TAG_DIGITAL_GYRO_DATA
{

    int		countPick[9];		 	
    int 	Gi[3];				 
    int 	wa[9];				 
    int 	wal[9];				 
 	int		JoinTotal;          
 	int  	gyroStatus0;		
 	int 	gyroStatus1;		 
    int 	W[3];				 
    int 	SignFlag[9] ; 		   
	int 	Rtemp[3][5];		 
	int 	stateFlag[9];		
	
} SGyroData;
typedef struct TAG_UPS_2MS
{	
	int flgABChoose;				
    int wPulse;         			
	int stateFlag[2];				
    
} SThrDistribute;
typedef struct __InitVar
{

	int		countInt32ms;
	int		countSate;
	int		countPublic;
	int		countMode;
	int		flgPRSAM;
	int		flgGryoCalc;
	int		flg160INT;
	SGyroData		mGyroData;
	SFratemodulator mModulator;
	SThrDistribute	mThrDistribute;
	SFWarning		mFWarning;

} InitVar;

/*@
 requires \valid(pIp) && \valid(pIp->mGyroData.countPick+ (0..9)) && \valid(pIp->mGyroData.Gi+ (0..3)) && \valid(pIp->mGyroData.wa+ (0..9)) && \valid(pIp->mGyroData.wal+ (0..9)) && \valid(pIp->mGyroData.W+ (0..3)) && \valid(pIp->mGyroData.SignFlag+ (0..9)) && \valid(pIp->mGyroData.Rtemp+ (0..3)) && \valid(pIp->mGyroData.stateFlag+ (0..9)) && \valid(pIp->mThrDistribute.stateFlag+ (0..2)) ;
 requires \separated(pIp,pIp->mGyroData.countPick+(0..9),pIp->mGyroData.Gi+(0..3),pIp->mGyroData.wa+(0..9),pIp->mGyroData.wal+(0..9),pIp->mGyroData.W+(0..3),pIp->mGyroData.SignFlag+(0..9),pIp->mGyroData.Rtemp+(0..3),pIp->mGyroData.stateFlag+(0..9),pIp->mThrDistribute.stateFlag+(0..2)) ;

ensures pIp->mGyroData.countPick[0] == \old(pIp->mGyroData.countPick[0]) && pIp->mGyroData.countPick[1] == \old(pIp->mGyroData.countPick[1]) && pIp->mGyroData.countPick[2] == \old(pIp->mGyroData.countPick[2]) && pIp->mGyroData.countPick[3] == \old(pIp->mGyroData.countPick[3]) && pIp->mGyroData.countPick[4] == \old(pIp->mGyroData.countPick[4]) && pIp->mGyroData.countPick[5] == \old(pIp->mGyroData.countPick[5]) && pIp->mGyroData.countPick[6] == \old(pIp->mGyroData.countPick[6]) && pIp->mGyroData.countPick[7] == \old(pIp->mGyroData.countPick[7]) && pIp->mGyroData.countPick[8] == \old(pIp->mGyroData.countPick[8]) && pIp->mGyroData.Gi[0] == \old(pIp->mGyroData.Gi[0]) && pIp->mGyroData.Gi[1] == \old(pIp->mGyroData.Gi[1]) && pIp->mGyroData.Gi[2] == \old(pIp->mGyroData.Gi[2]) && pIp->mGyroData.wa[0] == \old(pIp->mGyroData.wa[0]) && pIp->mGyroData.wa[1] == \old(pIp->mGyroData.wa[1]) && pIp->mGyroData.wa[2] == \old(pIp->mGyroData.wa[2]) && pIp->mGyroData.wa[3] == \old(pIp->mGyroData.wa[3]) && pIp->mGyroData.wa[4] == \old(pIp->mGyroData.wa[4]) && pIp->mGyroData.wa[5] == \old(pIp->mGyroData.wa[5]) && pIp->mGyroData.wa[6] == \old(pIp->mGyroData.wa[6]) && pIp->mGyroData.wa[7] == \old(pIp->mGyroData.wa[7]) && pIp->mGyroData.wa[8] == \old(pIp->mGyroData.wa[8]) && pIp->mGyroData.wal[0] == \old(pIp->mGyroData.wal[0]) && pIp->mGyroData.wal[1] == \old(pIp->mGyroData.wal[1]) && pIp->mGyroData.wal[2] == \old(pIp->mGyroData.wal[2]) && pIp->mGyroData.wal[3] == \old(pIp->mGyroData.wal[3]) && pIp->mGyroData.wal[4] == \old(pIp->mGyroData.wal[4]) && pIp->mGyroData.wal[5] == \old(pIp->mGyroData.wal[5]) && pIp->mGyroData.wal[6] == \old(pIp->mGyroData.wal[6]) && pIp->mGyroData.wal[7] == \old(pIp->mGyroData.wal[7]) && pIp->mGyroData.wal[8] == \old(pIp->mGyroData.wal[8]) && pIp->mGyroData.W[0] == \old(pIp->mGyroData.W[0]) && pIp->mGyroData.W[1] == \old(pIp->mGyroData.W[1]) && pIp->mGyroData.W[2] == \old(pIp->mGyroData.W[2]) && pIp->mGyroData.SignFlag[0] == \old(pIp->mGyroData.SignFlag[0]) && pIp->mGyroData.SignFlag[1] == \old(pIp->mGyroData.SignFlag[1]) && pIp->mGyroData.SignFlag[2] == \old(pIp->mGyroData.SignFlag[2]) && pIp->mGyroData.SignFlag[3] == \old(pIp->mGyroData.SignFlag[3]) && pIp->mGyroData.SignFlag[4] == \old(pIp->mGyroData.SignFlag[4]) && pIp->mGyroData.SignFlag[5] == \old(pIp->mGyroData.SignFlag[5]) && pIp->mGyroData.SignFlag[6] == \old(pIp->mGyroData.SignFlag[6]) && pIp->mGyroData.SignFlag[7] == \old(pIp->mGyroData.SignFlag[7]) && pIp->mGyroData.SignFlag[8] == \old(pIp->mGyroData.SignFlag[8]) && pIp->mGyroData.Rtemp[0] == \old(pIp->mGyroData.Rtemp[0]) && pIp->mGyroData.Rtemp[1] == \old(pIp->mGyroData.Rtemp[1]) && pIp->mGyroData.Rtemp[2] == \old(pIp->mGyroData.Rtemp[2]) && pIp->mGyroData.stateFlag[0] == \old(pIp->mGyroData.stateFlag[0]) && pIp->mGyroData.stateFlag[1] == \old(pIp->mGyroData.stateFlag[1]) && pIp->mGyroData.stateFlag[2] == \old(pIp->mGyroData.stateFlag[2]) && pIp->mGyroData.stateFlag[3] == \old(pIp->mGyroData.stateFlag[3]) && pIp->mGyroData.stateFlag[4] == \old(pIp->mGyroData.stateFlag[4]) && pIp->mGyroData.stateFlag[5] == \old(pIp->mGyroData.stateFlag[5]) && pIp->mGyroData.stateFlag[6] == \old(pIp->mGyroData.stateFlag[6]) && pIp->mGyroData.stateFlag[7] == \old(pIp->mGyroData.stateFlag[7]) && pIp->mGyroData.stateFlag[8] == \old(pIp->mGyroData.stateFlag[8]) && pIp->mThrDistribute.stateFlag[0] == \old(pIp->mThrDistribute.stateFlag[0]) && pIp->mThrDistribute.stateFlag[1] == \old(pIp->mThrDistribute.stateFlag[1]) ==> pIp->countInt32ms == 0&&pIp->countSate == 0&&pIp->countPublic == 0&&pIp->countMode == 0&&pIp->flgPRSAM == 13107&&pIp->flgGryoCalc == 0&&pIp->flg160INT == 13107&&pIp->mGyroData.JoinTotal == \old(pIp->mGyroData.JoinTotal)&&pIp->mGyroData.gyroStatus0 == 0&&pIp->mGyroData.gyroStatus1 == 0&&pIp->mModulator.u == \old(pIp->mModulator.u)&&pIp->mModulator.r == 0&&pIp->mModulator.Yp == \old(pIp->mModulator.Yp)&&pIp->mModulator.Yn == \old(pIp->mModulator.Yn)&&pIp->mThrDistribute.flgABChoose == \old(pIp->mThrDistribute.flgABChoose)&&pIp->mThrDistribute.wPulse == 0&&pIp->mFWarning.CWsp == \old(pIp->mFWarning.CWsp)&&pIp->mFWarning.CWtf == \old(pIp->mFWarning.CWtf)&&pIp->mFWarning.Wsp == \old(pIp->mFWarning.Wsp)&&pIp->mFWarning.Wtf == \old(pIp->mFWarning.Wtf)&&pIp->mFWarning.Wav == \old(pIp->mFWarning.Wav)&&pIp->mFWarning.flgups == \old(pIp->mFWarning.flgups)&&pIp->mFWarning.flgModeChange == \old(pIp->mFWarning.flgModeChange)&&pIp->mFWarning.countAV == \old(pIp->mFWarning.countAV)&&pIp->mFWarning.countSPLost == 0&&pIp->mFWarning.countSPSeen == 0&&pIp->mFWarning.countSPset == 0&&pIp->mFWarning.countUPSpc == 0;

*/

void InitVarFun(InitVar *pIp)

{

	pIp -> flg160INT = 0x3333 ;
	pIp -> flgPRSAM = 0x3333 ;

	pIp -> mGyroData.gyroStatus0 = 0 ;
	pIp -> mGyroData.gyroStatus1 = 0 ;

	pIp -> countSate    = 0 ;
	pIp -> countPublic  = 0 ;
	pIp -> countMode    = 0 ;
	pIp -> countInt32ms = 0 ;

	pIp -> mFWarning.countSPLost = 0 ;
	pIp -> mFWarning.countSPSeen = 0 ;
	pIp -> mFWarning.countSPset  = 0 ;
	pIp -> mFWarning.countUPSpc  = 0 ;

	pIp -> mThrDistribute.wPulse = 0x0 ;

	pIp -> mModulator.r = 0 ;

	pIp -> flgGryoCalc = 0 ;

	return;
}