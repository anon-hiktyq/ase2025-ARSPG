typedef struct TAG_UPS_2MS
{	
	int flgABChoose;				
    int wPulse;
	int stateFlag[2];				
    
} SThrDistribute;
typedef struct __JetDataGet
{
/* 输入端口 */
	/* 输出端口 */
	/* 输入输出端口 */
    int *                   addr_e;
	SThrDistribute			mThrDistribute;
	/* 状态变量 */
	/* 参数变量 */
} JetDataGet;

/*@
 requires \valid(pIp) && \valid(pIp->addr_e) && \valid(pIp->mThrDistribute.stateFlag+ (0..2)) ;
 requires \separated(pIp,pIp->addr_e,pIp->mThrDistribute.stateFlag+(0..2)) ;

ensures pIp->mThrDistribute.stateFlag[1] == 1 && pIp->mThrDistribute.stateFlag[0] == 1 && pIp->mThrDistribute.stateFlag[0] == \old(pIp->mThrDistribute.stateFlag[0]) && pIp->mThrDistribute.stateFlag[1] == \old(pIp->mThrDistribute.stateFlag[1]) ==> pIp->addr_e == \old(pIp->addr_e)&&*pIp->addr_e == \old(*pIp->addr_e)&&pIp->mThrDistribute.flgABChoose == 204&&pIp->mThrDistribute.wPulse == \old(pIp->mThrDistribute.wPulse);

ensures pIp->mThrDistribute.stateFlag[1] == 1 && pIp->mThrDistribute.stateFlag[0] == 0 && pIp->mThrDistribute.stateFlag[0] != 1 && pIp->mThrDistribute.stateFlag[0] == \old(pIp->mThrDistribute.stateFlag[0]) && pIp->mThrDistribute.stateFlag[1] == \old(pIp->mThrDistribute.stateFlag[1]) ==> pIp->addr_e == \old(pIp->addr_e)&&*pIp->addr_e == \old(*pIp->addr_e)&&pIp->mThrDistribute.flgABChoose == 51&&pIp->mThrDistribute.wPulse == \old(pIp->mThrDistribute.wPulse);

ensures pIp->mThrDistribute.stateFlag[0] != 0 && pIp->mThrDistribute.stateFlag[0] != 1 && pIp->mThrDistribute.stateFlag[0] == \old(pIp->mThrDistribute.stateFlag[0]) && pIp->mThrDistribute.stateFlag[1] == \old(pIp->mThrDistribute.stateFlag[1]) ==> pIp->addr_e == \old(pIp->addr_e)&&*pIp->addr_e == \old(*pIp->addr_e)&&pIp->mThrDistribute.flgABChoose == 0&&pIp->mThrDistribute.wPulse == \old(pIp->mThrDistribute.wPulse);

ensures pIp->mThrDistribute.stateFlag[1] != 1 && pIp->mThrDistribute.stateFlag[0] == 0 && pIp->mThrDistribute.stateFlag[0] != 1 && pIp->mThrDistribute.stateFlag[0] == \old(pIp->mThrDistribute.stateFlag[0]) && pIp->mThrDistribute.stateFlag[1] == \old(pIp->mThrDistribute.stateFlag[1]) ==> pIp->addr_e == \old(pIp->addr_e)&&*pIp->addr_e == \old(*pIp->addr_e)&&pIp->mThrDistribute.flgABChoose == 0&&pIp->mThrDistribute.wPulse == \old(pIp->mThrDistribute.wPulse);

ensures pIp->mThrDistribute.stateFlag[0] != 0 && pIp->mThrDistribute.stateFlag[1] != 1 && pIp->mThrDistribute.stateFlag[0] == 1 && pIp->mThrDistribute.stateFlag[0] == \old(pIp->mThrDistribute.stateFlag[0]) && pIp->mThrDistribute.stateFlag[1] == \old(pIp->mThrDistribute.stateFlag[1]) ==> pIp->addr_e == \old(pIp->addr_e)&&*pIp->addr_e == \old(*pIp->addr_e)&&pIp->mThrDistribute.flgABChoose == 0&&pIp->mThrDistribute.wPulse == \old(pIp->mThrDistribute.wPulse);

*/

void ThrABAutoChoose(JetDataGet *pIp)

{

    if ((pIp -> mThrDistribute.stateFlag[0] == 1) &&
        (pIp -> mThrDistribute.stateFlag[1] == 1))
    {

        pIp -> mThrDistribute.flgABChoose = 0xCC ;
    }
    else if ((pIp -> mThrDistribute.stateFlag[0] == 0) &&
             (pIp -> mThrDistribute.stateFlag[1] == 1))
    {
        pIp -> mThrDistribute.flgABChoose = 0x33 ;
    }
    else
    {
        pIp -> mThrDistribute.flgABChoose = 0x00 ;
    }

    return ;
}