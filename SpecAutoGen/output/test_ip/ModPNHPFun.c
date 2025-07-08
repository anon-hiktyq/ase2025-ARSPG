typedef struct __ModPNHP
{
/* 接口函数 */
/* 输入端口 */
	int		x;
	int	 halfperiod;
	/* 输出端口 */
	int 	npp2;
	int*	ret;
	/* 输入输出端口 */
	/* 状态变量 */
	/* 参数变量 */
} ModPNHP;

/*@
 requires \valid(pIp) && \valid(pIp->ret) ;
 requires \separated(pIp,pIp->ret) ;

ensures pIp->x == \old(pIp->x)&&pIp->halfperiod == \old(pIp->halfperiod)&&pIp->npp2 == \old(pIp->x) - 2 * \old(pIp->halfperiod)&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == \old(pIp->x) - 2 * \old(pIp->halfperiod);

*/

void ModPNHPFun(ModPNHP *pIp)

{

    int period;

    period = 2 * pIp -> halfperiod;

    pIp -> npp2 = pIp -> x - period ;

    *(pIp -> ret) = pIp -> npp2;
}