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

/*@
 requires \valid(pIp) ;

ensures \old(pIp->mDSSData.stateFlag_A) != 0 && \old(pIp->mDSSData.stateFlag_A) == 1 ==> pIp->mDSSData.stateFlag_A == \old(pIp->mDSSData.stateFlag_A)&&pIp->mDSSData.stateFlag_B == \old(pIp->mDSSData.stateFlag_B)&&pIp->mDSSData.royaw == \old(pIp->mDSSData.royaw)&&pIp->mDSSData.piyaw == \old(pIp->mDSSData.piyaw)&&pIp->mDSSData.flgSP == \old(pIp->mDSSData.flgSP);

ensures \old(pIp->mDSSData.stateFlag_A) != 1 && \old(pIp->mDSSData.stateFlag_A) != 1 ==> pIp->mDSSData.stateFlag_A == \old(pIp->mDSSData.stateFlag_A)&&pIp->mDSSData.stateFlag_B == \old(pIp->mDSSData.stateFlag_B)&&pIp->mDSSData.royaw == \old(pIp->mDSSData.royaw)&&pIp->mDSSData.piyaw == \old(pIp->mDSSData.piyaw)&&pIp->mDSSData.flgSP == \old(pIp->mDSSData.flgSP);

*/

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