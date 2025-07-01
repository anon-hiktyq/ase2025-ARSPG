
typedef struct TAG_FALSE_RATE_MODULATOR
{
	
	int 	u;						
	int   	r;						
	int  	Yp;						
	int 	Yn;						
	                            	
}SFratemodulator;

typedef struct TAG_UPS_2MS
{	
	int flgABChoose;				
    int wPulse;
	int stateFlag[2];				
    
} SThrDistribute;

typedef struct __ThrusterCtrlLogic
{

	SFratemodulator 		fmModulator;
	SFratemodulator 		smModulator;
	SFratemodulator 		tmModulator;
	SThrDistribute			mThrDistribute;
	
} ThrusterCtrlLogic;

void ThrusterCtrlLogicFun(ThrusterCtrlLogic *pIp)
{

	if ( pIp -> fmModulator.Yp != 0)
	{
		pIp -> mThrDistribute.wPulse = pIp -> mThrDistribute.wPulse | 0x04 ;
	}

	if ( pIp -> fmModulator.Yn != 0)
	{
		pIp -> mThrDistribute.wPulse = pIp -> mThrDistribute.wPulse | 0x08 ;
	}

	if ( pIp -> smModulator.Yp != 0)
	{
		pIp -> mThrDistribute.wPulse = pIp -> mThrDistribute.wPulse | 0x10 ;
	}

	if ( pIp -> smModulator.Yn != 0)
	{
		pIp -> mThrDistribute.wPulse = pIp -> mThrDistribute.wPulse | 0x20 ;
	}

	if ( pIp -> tmModulator.Yp != 0)
	{
		pIp -> mThrDistribute.wPulse = pIp -> mThrDistribute.wPulse | 0x40 ;
	}

	if ( pIp -> tmModulator.Yn != 0)
	{
		pIp -> mThrDistribute.wPulse = pIp -> mThrDistribute.wPulse | 0x80 ;
	}

	return ;
}