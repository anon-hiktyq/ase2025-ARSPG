



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

void JetDataGetFun(JetDataGet *pIp)
{

    ThrABAutoChoose(pIp);

	if(( *(pIp->addr_e) & 0x4) == 0x4)
	{
		pIp -> mThrDistribute.stateFlag[0] = 1;
	}
	else
	{
		pIp -> mThrDistribute.stateFlag[0] = 0;
	}

	if(( *(pIp->addr_e) & 0x8) == 0x8)
	{
		pIp -> mThrDistribute.stateFlag[1] = 1;
	}
	else
	{
		pIp -> mThrDistribute.stateFlag[1] = 0;
	}

	return;
}