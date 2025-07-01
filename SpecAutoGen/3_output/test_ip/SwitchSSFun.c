
typedef struct TAG_DSS_DATA
{
 	int stateFlag_A;
 	int stateFlag_B;
 	int royaw;
 	int piyaw;
	int flgSP;
}SDSSData;


typedef struct __SwitchSS
{
	SDSSData			mDSSData;
} SwitchSS;


void SwitchSSFun(SwitchSS *pIp)
{

    if (pIp -> mDSSData.stateFlag_A == 1)
    {

        pIp -> mDSSData.stateFlag_A == 0;
		
    }
    else
    {
        pIp -> mDSSData.stateFlag_A == 1;
    }

    return;
}