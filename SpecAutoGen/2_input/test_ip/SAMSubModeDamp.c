typedef struct __SAMSubModeDamp
{
/* 输入端口 */
	int 		rate[3];
    int          max;
	int			tmax;
	int			countPublic;
	int		    countMode;
	int         flgMode;
	/* 输出端口 */
	/* 输入输出端口 */
	/* 状态变量 */
	/* 参数变量 */
} SAMSubModeDamp;



void SAMSubModeDampFun(SAMSubModeDamp *pIp)
{


    //TripleMax(pIp);
    int absfx1 = pIp->rate[0];
    int absfy2 = pIp->rate[1];
    int absfz3 = pIp->rate[2];

    if (pIp->rate[0] < 0)
    {
        absfx1 = -pIp->rate[0];
    }

    if (pIp->rate[1] < 0)
    {
        absfy2 = -pIp->rate[1];
    }

    if (pIp->rate[2] < 0)
    {
        absfz3 = -pIp->rate[2];
    }

    if (absfx1 > absfy2)
    {
        pIp->tmax = absfx1;
    }
    else
    {
        pIp->tmax = absfy2;
    }

    if (absfz3 > pIp->tmax)
    {
        pIp->tmax = absfz3;
    }

    if (  pIp->tmax < pIp -> max )
    {
        pIp -> countPublic++ ;
    }

    if (( pIp -> countPublic > 350 ) || ( pIp -> countMode > 1000 ))
    {
		pIp->flgMode = 0x11 ;
        pIp -> countMode = 0 ;
        pIp -> countPublic = 0 ;
    }

    return ;
}