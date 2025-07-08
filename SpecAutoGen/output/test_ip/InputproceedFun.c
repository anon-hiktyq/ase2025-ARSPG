typedef struct TAG_DSS_DATA
{	
	int     stateFlag_A;		
	int     stateFlag_B;			
	int 	royaw;
	int  	piyaw;
    int     flgSP;				
}SDSSData;
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
typedef struct TAG_ATTITUDE_PARA     	
{                                    	
	                                 	
	int 	angle[3];			 
	int 	rate[3]; 			 
	                                 	
}SAttitude;
typedef struct __Inputproceed
{
	int  		       flgGryoCalc;
	int                flgMode;
	SDSSData			mDSSData;
	SAttitude			mAttitude;
	SGyroData			mGyroData;

} Inputproceed;

/*@
 requires \valid(pIp) && \valid(pIp->mAttitude.angle+ (0..3)) && \valid(pIp->mAttitude.rate+ (0..3)) && \valid(pIp->mGyroData.countPick+ (0..9)) && \valid(pIp->mGyroData.Gi+ (0..3)) && \valid(pIp->mGyroData.wa+ (0..9)) && \valid(pIp->mGyroData.wal+ (0..9)) && \valid(pIp->mGyroData.W+ (0..3)) && \valid(pIp->mGyroData.SignFlag+ (0..9)) && \valid(pIp->mGyroData.Rtemp+ (0..3)) && \valid(pIp->mGyroData.stateFlag+ (0..9)) ;
 requires \separated(pIp,pIp->mAttitude.angle+(0..3),pIp->mAttitude.rate+(0..3),pIp->mGyroData.countPick+(0..9),pIp->mGyroData.Gi+(0..3),pIp->mGyroData.wa+(0..9),pIp->mGyroData.wal+(0..9),pIp->mGyroData.W+(0..3),pIp->mGyroData.SignFlag+(0..9),pIp->mGyroData.Rtemp+(0..3),pIp->mGyroData.stateFlag+(0..9)) ;

ensures \old(pIp->flgMode) != 51 && pIp->mAttitude.angle[0] == \old(pIp->mAttitude.angle[0]) && pIp->mAttitude.angle[1] == \old(pIp->mAttitude.angle[1]) && pIp->mAttitude.angle[2] == \old(pIp->mAttitude.angle[2]) && pIp->mAttitude.rate[0] == \old(pIp->mAttitude.rate[0]) && pIp->mAttitude.rate[1] == \old(pIp->mAttitude.rate[1]) && pIp->mAttitude.rate[2] == \old(pIp->mAttitude.rate[2]) && pIp->mGyroData.countPick[0] == \old(pIp->mGyroData.countPick[0]) && pIp->mGyroData.countPick[1] == \old(pIp->mGyroData.countPick[1]) && pIp->mGyroData.countPick[2] == \old(pIp->mGyroData.countPick[2]) && pIp->mGyroData.countPick[3] == \old(pIp->mGyroData.countPick[3]) && pIp->mGyroData.countPick[4] == \old(pIp->mGyroData.countPick[4]) && pIp->mGyroData.countPick[5] == \old(pIp->mGyroData.countPick[5]) && pIp->mGyroData.countPick[6] == \old(pIp->mGyroData.countPick[6]) && pIp->mGyroData.countPick[7] == \old(pIp->mGyroData.countPick[7]) && pIp->mGyroData.countPick[8] == \old(pIp->mGyroData.countPick[8]) && pIp->mGyroData.Gi[0] == \old(pIp->mGyroData.Gi[0]) && pIp->mGyroData.Gi[1] == \old(pIp->mGyroData.Gi[1]) && pIp->mGyroData.Gi[2] == \old(pIp->mGyroData.Gi[2]) && pIp->mGyroData.wa[0] == \old(pIp->mGyroData.wa[0]) && pIp->mGyroData.wa[1] == \old(pIp->mGyroData.wa[1]) && pIp->mGyroData.wa[2] == \old(pIp->mGyroData.wa[2]) && pIp->mGyroData.wa[3] == \old(pIp->mGyroData.wa[3]) && pIp->mGyroData.wa[4] == \old(pIp->mGyroData.wa[4]) && pIp->mGyroData.wa[5] == \old(pIp->mGyroData.wa[5]) && pIp->mGyroData.wa[6] == \old(pIp->mGyroData.wa[6]) && pIp->mGyroData.wa[7] == \old(pIp->mGyroData.wa[7]) && pIp->mGyroData.wa[8] == \old(pIp->mGyroData.wa[8]) && pIp->mGyroData.wal[0] == \old(pIp->mGyroData.wal[0]) && pIp->mGyroData.wal[1] == \old(pIp->mGyroData.wal[1]) && pIp->mGyroData.wal[2] == \old(pIp->mGyroData.wal[2]) && pIp->mGyroData.wal[3] == \old(pIp->mGyroData.wal[3]) && pIp->mGyroData.wal[4] == \old(pIp->mGyroData.wal[4]) && pIp->mGyroData.wal[5] == \old(pIp->mGyroData.wal[5]) && pIp->mGyroData.wal[6] == \old(pIp->mGyroData.wal[6]) && pIp->mGyroData.wal[7] == \old(pIp->mGyroData.wal[7]) && pIp->mGyroData.wal[8] == \old(pIp->mGyroData.wal[8]) && pIp->mGyroData.W[0] == \old(pIp->mGyroData.W[0]) && pIp->mGyroData.W[1] == \old(pIp->mGyroData.W[1]) && pIp->mGyroData.W[2] == \old(pIp->mGyroData.W[2]) && pIp->mGyroData.SignFlag[0] == \old(pIp->mGyroData.SignFlag[0]) && pIp->mGyroData.SignFlag[1] == \old(pIp->mGyroData.SignFlag[1]) && pIp->mGyroData.SignFlag[2] == \old(pIp->mGyroData.SignFlag[2]) && pIp->mGyroData.SignFlag[3] == \old(pIp->mGyroData.SignFlag[3]) && pIp->mGyroData.SignFlag[4] == \old(pIp->mGyroData.SignFlag[4]) && pIp->mGyroData.SignFlag[5] == \old(pIp->mGyroData.SignFlag[5]) && pIp->mGyroData.SignFlag[6] == \old(pIp->mGyroData.SignFlag[6]) && pIp->mGyroData.SignFlag[7] == \old(pIp->mGyroData.SignFlag[7]) && pIp->mGyroData.SignFlag[8] == \old(pIp->mGyroData.SignFlag[8]) && pIp->mGyroData.Rtemp[0] == \old(pIp->mGyroData.Rtemp[0]) && pIp->mGyroData.Rtemp[1] == \old(pIp->mGyroData.Rtemp[1]) && pIp->mGyroData.Rtemp[2] == \old(pIp->mGyroData.Rtemp[2]) && pIp->mGyroData.stateFlag[0] == \old(pIp->mGyroData.stateFlag[0]) && pIp->mGyroData.stateFlag[1] == \old(pIp->mGyroData.stateFlag[1]) && pIp->mGyroData.stateFlag[2] == \old(pIp->mGyroData.stateFlag[2]) && pIp->mGyroData.stateFlag[3] == \old(pIp->mGyroData.stateFlag[3]) && pIp->mGyroData.stateFlag[4] == \old(pIp->mGyroData.stateFlag[4]) && pIp->mGyroData.stateFlag[5] == \old(pIp->mGyroData.stateFlag[5]) && pIp->mGyroData.stateFlag[6] == \old(pIp->mGyroData.stateFlag[6]) && pIp->mGyroData.stateFlag[7] == \old(pIp->mGyroData.stateFlag[7]) && pIp->mGyroData.stateFlag[8] == \old(pIp->mGyroData.stateFlag[8]) ==> pIp->flgGryoCalc == \old(pIp->flgGryoCalc)&&pIp->flgMode == \old(pIp->flgMode)&&pIp->mDSSData.stateFlag_A == \old(pIp->mDSSData.stateFlag_A)&&pIp->mDSSData.stateFlag_B == \old(pIp->mDSSData.stateFlag_B)&&pIp->mDSSData.royaw == \old(pIp->mDSSData.royaw)&&pIp->mDSSData.piyaw == \old(pIp->mDSSData.piyaw)&&pIp->mDSSData.flgSP == \old(pIp->mDSSData.flgSP)&&pIp->mGyroData.JoinTotal == \old(pIp->mGyroData.JoinTotal)&&pIp->mGyroData.gyroStatus0 == \old(pIp->mGyroData.gyroStatus0)&&pIp->mGyroData.gyroStatus1 == \old(pIp->mGyroData.gyroStatus1);

ensures \old(pIp->mDSSData.flgSP) != 1 && \old(pIp->flgMode) == 51 && pIp->mAttitude.angle[0] == \old(pIp->mAttitude.angle[0]) && pIp->mAttitude.angle[1] == \old(pIp->mAttitude.angle[1]) && pIp->mAttitude.angle[2] == \old(pIp->mAttitude.angle[2]) && pIp->mAttitude.rate[0] == \old(pIp->mAttitude.rate[0]) && pIp->mAttitude.rate[1] == \old(pIp->mAttitude.rate[1]) && pIp->mAttitude.rate[2] == \old(pIp->mAttitude.rate[2]) && pIp->mGyroData.countPick[0] == \old(pIp->mGyroData.countPick[0]) && pIp->mGyroData.countPick[1] == \old(pIp->mGyroData.countPick[1]) && pIp->mGyroData.countPick[2] == \old(pIp->mGyroData.countPick[2]) && pIp->mGyroData.countPick[3] == \old(pIp->mGyroData.countPick[3]) && pIp->mGyroData.countPick[4] == \old(pIp->mGyroData.countPick[4]) && pIp->mGyroData.countPick[5] == \old(pIp->mGyroData.countPick[5]) && pIp->mGyroData.countPick[6] == \old(pIp->mGyroData.countPick[6]) && pIp->mGyroData.countPick[7] == \old(pIp->mGyroData.countPick[7]) && pIp->mGyroData.countPick[8] == \old(pIp->mGyroData.countPick[8]) && pIp->mGyroData.Gi[0] == \old(pIp->mGyroData.Gi[0]) && pIp->mGyroData.Gi[1] == \old(pIp->mGyroData.Gi[1]) && pIp->mGyroData.Gi[2] == \old(pIp->mGyroData.Gi[2]) && pIp->mGyroData.wa[0] == \old(pIp->mGyroData.wa[0]) && pIp->mGyroData.wa[1] == \old(pIp->mGyroData.wa[1]) && pIp->mGyroData.wa[2] == \old(pIp->mGyroData.wa[2]) && pIp->mGyroData.wa[3] == \old(pIp->mGyroData.wa[3]) && pIp->mGyroData.wa[4] == \old(pIp->mGyroData.wa[4]) && pIp->mGyroData.wa[5] == \old(pIp->mGyroData.wa[5]) && pIp->mGyroData.wa[6] == \old(pIp->mGyroData.wa[6]) && pIp->mGyroData.wa[7] == \old(pIp->mGyroData.wa[7]) && pIp->mGyroData.wa[8] == \old(pIp->mGyroData.wa[8]) && pIp->mGyroData.wal[0] == \old(pIp->mGyroData.wal[0]) && pIp->mGyroData.wal[1] == \old(pIp->mGyroData.wal[1]) && pIp->mGyroData.wal[2] == \old(pIp->mGyroData.wal[2]) && pIp->mGyroData.wal[3] == \old(pIp->mGyroData.wal[3]) && pIp->mGyroData.wal[4] == \old(pIp->mGyroData.wal[4]) && pIp->mGyroData.wal[5] == \old(pIp->mGyroData.wal[5]) && pIp->mGyroData.wal[6] == \old(pIp->mGyroData.wal[6]) && pIp->mGyroData.wal[7] == \old(pIp->mGyroData.wal[7]) && pIp->mGyroData.wal[8] == \old(pIp->mGyroData.wal[8]) && pIp->mGyroData.W[0] == \old(pIp->mGyroData.W[0]) && pIp->mGyroData.W[1] == \old(pIp->mGyroData.W[1]) && pIp->mGyroData.W[2] == \old(pIp->mGyroData.W[2]) && pIp->mGyroData.SignFlag[0] == \old(pIp->mGyroData.SignFlag[0]) && pIp->mGyroData.SignFlag[1] == \old(pIp->mGyroData.SignFlag[1]) && pIp->mGyroData.SignFlag[2] == \old(pIp->mGyroData.SignFlag[2]) && pIp->mGyroData.SignFlag[3] == \old(pIp->mGyroData.SignFlag[3]) && pIp->mGyroData.SignFlag[4] == \old(pIp->mGyroData.SignFlag[4]) && pIp->mGyroData.SignFlag[5] == \old(pIp->mGyroData.SignFlag[5]) && pIp->mGyroData.SignFlag[6] == \old(pIp->mGyroData.SignFlag[6]) && pIp->mGyroData.SignFlag[7] == \old(pIp->mGyroData.SignFlag[7]) && pIp->mGyroData.SignFlag[8] == \old(pIp->mGyroData.SignFlag[8]) && pIp->mGyroData.Rtemp[0] == \old(pIp->mGyroData.Rtemp[0]) && pIp->mGyroData.Rtemp[1] == \old(pIp->mGyroData.Rtemp[1]) && pIp->mGyroData.Rtemp[2] == \old(pIp->mGyroData.Rtemp[2]) && pIp->mGyroData.stateFlag[0] == \old(pIp->mGyroData.stateFlag[0]) && pIp->mGyroData.stateFlag[1] == \old(pIp->mGyroData.stateFlag[1]) && pIp->mGyroData.stateFlag[2] == \old(pIp->mGyroData.stateFlag[2]) && pIp->mGyroData.stateFlag[3] == \old(pIp->mGyroData.stateFlag[3]) && pIp->mGyroData.stateFlag[4] == \old(pIp->mGyroData.stateFlag[4]) && pIp->mGyroData.stateFlag[5] == \old(pIp->mGyroData.stateFlag[5]) && pIp->mGyroData.stateFlag[6] == \old(pIp->mGyroData.stateFlag[6]) && pIp->mGyroData.stateFlag[7] == \old(pIp->mGyroData.stateFlag[7]) && pIp->mGyroData.stateFlag[8] == \old(pIp->mGyroData.stateFlag[8]) ==> pIp->flgGryoCalc == \old(pIp->flgGryoCalc)&&pIp->flgMode == \old(pIp->flgMode)&&pIp->mDSSData.stateFlag_A == \old(pIp->mDSSData.stateFlag_A)&&pIp->mDSSData.stateFlag_B == \old(pIp->mDSSData.stateFlag_B)&&pIp->mDSSData.royaw == \old(pIp->mDSSData.royaw)&&pIp->mDSSData.piyaw == \old(pIp->mDSSData.piyaw)&&pIp->mDSSData.flgSP == \old(pIp->mDSSData.flgSP)&&pIp->mGyroData.JoinTotal == \old(pIp->mGyroData.JoinTotal)&&pIp->mGyroData.gyroStatus0 == \old(pIp->mGyroData.gyroStatus0)&&pIp->mGyroData.gyroStatus1 == \old(pIp->mGyroData.gyroStatus1);

ensures \old(pIp->mDSSData.flgSP) == 1 && \old(pIp->flgMode) == 51 && pIp->mAttitude.angle[0] == \old(pIp->mAttitude.angle[0]) && pIp->mAttitude.angle[1] == \old(pIp->mAttitude.angle[1]) && pIp->mAttitude.angle[2] == \old(pIp->mAttitude.angle[2]) && pIp->mAttitude.rate[0] == \old(pIp->mAttitude.rate[0]) && pIp->mAttitude.rate[1] == \old(pIp->mAttitude.rate[1]) && pIp->mAttitude.rate[2] == \old(pIp->mAttitude.rate[2]) && pIp->mGyroData.countPick[0] == \old(pIp->mGyroData.countPick[0]) && pIp->mGyroData.countPick[1] == \old(pIp->mGyroData.countPick[1]) && pIp->mGyroData.countPick[2] == \old(pIp->mGyroData.countPick[2]) && pIp->mGyroData.countPick[3] == \old(pIp->mGyroData.countPick[3]) && pIp->mGyroData.countPick[4] == \old(pIp->mGyroData.countPick[4]) && pIp->mGyroData.countPick[5] == \old(pIp->mGyroData.countPick[5]) && pIp->mGyroData.countPick[6] == \old(pIp->mGyroData.countPick[6]) && pIp->mGyroData.countPick[7] == \old(pIp->mGyroData.countPick[7]) && pIp->mGyroData.countPick[8] == \old(pIp->mGyroData.countPick[8]) && pIp->mGyroData.Gi[0] == \old(pIp->mGyroData.Gi[0]) && pIp->mGyroData.Gi[1] == \old(pIp->mGyroData.Gi[1]) && pIp->mGyroData.Gi[2] == \old(pIp->mGyroData.Gi[2]) && pIp->mGyroData.wa[0] == \old(pIp->mGyroData.wa[0]) && pIp->mGyroData.wa[1] == \old(pIp->mGyroData.wa[1]) && pIp->mGyroData.wa[2] == \old(pIp->mGyroData.wa[2]) && pIp->mGyroData.wa[3] == \old(pIp->mGyroData.wa[3]) && pIp->mGyroData.wa[4] == \old(pIp->mGyroData.wa[4]) && pIp->mGyroData.wa[5] == \old(pIp->mGyroData.wa[5]) && pIp->mGyroData.wa[6] == \old(pIp->mGyroData.wa[6]) && pIp->mGyroData.wa[7] == \old(pIp->mGyroData.wa[7]) && pIp->mGyroData.wa[8] == \old(pIp->mGyroData.wa[8]) && pIp->mGyroData.wal[0] == \old(pIp->mGyroData.wal[0]) && pIp->mGyroData.wal[1] == \old(pIp->mGyroData.wal[1]) && pIp->mGyroData.wal[2] == \old(pIp->mGyroData.wal[2]) && pIp->mGyroData.wal[3] == \old(pIp->mGyroData.wal[3]) && pIp->mGyroData.wal[4] == \old(pIp->mGyroData.wal[4]) && pIp->mGyroData.wal[5] == \old(pIp->mGyroData.wal[5]) && pIp->mGyroData.wal[6] == \old(pIp->mGyroData.wal[6]) && pIp->mGyroData.wal[7] == \old(pIp->mGyroData.wal[7]) && pIp->mGyroData.wal[8] == \old(pIp->mGyroData.wal[8]) && pIp->mGyroData.W[0] == \old(pIp->mGyroData.W[0]) && pIp->mGyroData.W[1] == \old(pIp->mGyroData.W[1]) && pIp->mGyroData.W[2] == \old(pIp->mGyroData.W[2]) && pIp->mGyroData.SignFlag[0] == \old(pIp->mGyroData.SignFlag[0]) && pIp->mGyroData.SignFlag[1] == \old(pIp->mGyroData.SignFlag[1]) && pIp->mGyroData.SignFlag[2] == \old(pIp->mGyroData.SignFlag[2]) && pIp->mGyroData.SignFlag[3] == \old(pIp->mGyroData.SignFlag[3]) && pIp->mGyroData.SignFlag[4] == \old(pIp->mGyroData.SignFlag[4]) && pIp->mGyroData.SignFlag[5] == \old(pIp->mGyroData.SignFlag[5]) && pIp->mGyroData.SignFlag[6] == \old(pIp->mGyroData.SignFlag[6]) && pIp->mGyroData.SignFlag[7] == \old(pIp->mGyroData.SignFlag[7]) && pIp->mGyroData.SignFlag[8] == \old(pIp->mGyroData.SignFlag[8]) && pIp->mGyroData.Rtemp[0] == \old(pIp->mGyroData.Rtemp[0]) && pIp->mGyroData.Rtemp[1] == \old(pIp->mGyroData.Rtemp[1]) && pIp->mGyroData.Rtemp[2] == \old(pIp->mGyroData.Rtemp[2]) && pIp->mGyroData.stateFlag[0] == \old(pIp->mGyroData.stateFlag[0]) && pIp->mGyroData.stateFlag[1] == \old(pIp->mGyroData.stateFlag[1]) && pIp->mGyroData.stateFlag[2] == \old(pIp->mGyroData.stateFlag[2]) && pIp->mGyroData.stateFlag[3] == \old(pIp->mGyroData.stateFlag[3]) && pIp->mGyroData.stateFlag[4] == \old(pIp->mGyroData.stateFlag[4]) && pIp->mGyroData.stateFlag[5] == \old(pIp->mGyroData.stateFlag[5]) && pIp->mGyroData.stateFlag[6] == \old(pIp->mGyroData.stateFlag[6]) && pIp->mGyroData.stateFlag[7] == \old(pIp->mGyroData.stateFlag[7]) && pIp->mGyroData.stateFlag[8] == \old(pIp->mGyroData.stateFlag[8]) ==> pIp->flgGryoCalc == \old(pIp->flgGryoCalc)&&pIp->flgMode == \old(pIp->flgMode)&&pIp->mDSSData.stateFlag_A == \old(pIp->mDSSData.stateFlag_A)&&pIp->mDSSData.stateFlag_B == \old(pIp->mDSSData.stateFlag_B)&&pIp->mDSSData.royaw == \old(pIp->mDSSData.royaw)&&pIp->mDSSData.piyaw == \old(pIp->mDSSData.piyaw)&&pIp->mDSSData.flgSP == \old(pIp->mDSSData.flgSP)&&pIp->mGyroData.JoinTotal == \old(pIp->mGyroData.JoinTotal)&&pIp->mGyroData.gyroStatus0 == \old(pIp->mGyroData.gyroStatus0)&&pIp->mGyroData.gyroStatus1 == \old(pIp->mGyroData.gyroStatus1);

*/

void InputproceedFun(Inputproceed *pIp)

{

	if ( pIp->flgMode == 0x33 )
	{
		if ( pIp -> mDSSData.flgSP == 1 )
		{
        	pIp -> mAttitude.angle[0] = pIp -> mDSSData.royaw ;
        	pIp -> mAttitude.angle[1] = pIp -> mDSSData.piyaw ;

       		pIp -> mGyroData.Gi[0] = pIp -> mDSSData.royaw ;
       		pIp -> mGyroData.Gi[1] = pIp -> mDSSData.piyaw ;
		}
		else
		{
		    pIp -> mAttitude.angle[0] = pIp -> mGyroData.Gi[0] ;
        	pIp -> mAttitude.angle[1] = pIp -> mGyroData.Gi[1] ;
		}
	}

	else
	{
		pIp -> mAttitude.angle[0] = 0 ;
    	pIp -> mAttitude.angle[1] = 0 ;
	}

	pIp -> mAttitude.rate[0] = pIp -> mGyroData.W[0] ;
    pIp -> mAttitude.rate[1] = pIp -> mGyroData.W[1] ;
	pIp -> mAttitude.rate[2] = pIp -> mGyroData.W[2] ;

	return ;
}