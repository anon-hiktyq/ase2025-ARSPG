
typedef struct __Delay
{
    /* 输入端口 */
	int			delaytime;
	/* 输出端口 */
	/* 输入输出端口 */
	/* 状态变量 */
	/* 参数变量 */
} Delay;

void DelayFun(Delay* pIp)
{

    int t=0;

    
            
            /*@
          loop invariant (0<\at(pIp,Pre) -> delaytime) ==> (0 <= t <= \at(pIp,Pre) -> delaytime) ;
          loop invariant (!(0<\at(pIp,Pre) -> delaytime)) ==> ((t == 0)&&(pIp == \at(pIp,Pre))&&(\at(pIp,Pre)->delaytime == \at(pIp->delaytime,Pre)));
          loop invariant pIp == \at(pIp,Pre);
          loop invariant \at(pIp,Pre)->delaytime == \at(pIp->delaytime,Pre);
            */
            for (; t<pIp -> delaytime ; t++ )
    {
       ;
    }
            

    return ;
}
