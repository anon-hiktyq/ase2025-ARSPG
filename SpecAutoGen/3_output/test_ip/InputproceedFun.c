
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