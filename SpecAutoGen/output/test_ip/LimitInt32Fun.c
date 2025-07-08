typedef struct __LimitInt32
{
/* 接口函数 */
	int			in;
	int		    bound;
	/* 输出端口 */
	int		    value;
	int*		ret;
	/* 输入输出端口 */
	/* 状态变量 */
	/* 参数变量 */
} LimitInt32;

/*@
 requires \valid(pIp) && \valid(pIp->ret) ;
 requires \separated(pIp,pIp->ret) ;

ensures \old(pIp->in) >= -\old(pIp->bound) && \old(pIp->in) <= \old(pIp->bound) ==> pIp->in == \old(pIp->in)&&pIp->bound == \old(pIp->bound)&&pIp->value == \old(pIp->in)&&pIp->ret == \old(pIp->ret)&&*pIp->ret == \old(pIp->in);

ensures \old(pIp->in) < -\old(pIp->bound) && \old(pIp->in) <= \old(pIp->bound) ==> pIp->in == \old(pIp->in)&&pIp->bound == \old(pIp->bound)&&pIp->value == -\old(pIp->bound)&&pIp->ret == \old(pIp->ret)&&*\old(pIp->ret) == -\old(pIp->bound);

ensures \old(pIp->in) > \old(pIp->bound) ==> pIp->in == \old(pIp->in)&&pIp->bound == \old(pIp->bound)&&pIp->value == \old(pIp->bound)&&pIp->ret == \old(pIp->ret)&&*pIp->ret == \old(pIp->bound);

*/

void LimitInt32Fun(LimitInt32 *pIp)

{

    if (pIp -> in > pIp -> bound)
    {
        pIp -> value = pIp -> bound ;
    }
    else if (pIp -> in < -pIp -> bound)
    {
        pIp -> value = -pIp -> bound ;
    }
    else
    {
        pIp -> value = pIp -> in ;
    }

    *(pIp -> ret) = pIp -> value ;


}