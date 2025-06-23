typedef struct __Delay
{
/* 输入端口 */
	int			delaytime;
	/* 输出端口 */
	/* 输入输出端口 */
	/* 状态变量 */
	/* 参数变量 */
} Delay;

/*@
 requires \valid(pIp) ;

ensures \exists int delaytime, t_58;  t_58 >= \old(pIp->delaytime) && (0 < \old(pIp->delaytime) ==> t_58 <= \old(pIp->delaytime)) && (0 < \old(pIp->delaytime) ==> t_58 >= 0) && (!(0 < \old(pIp->delaytime)) ==> t_58 == 0 && pIp == pIp && \old(pIp->delaytime) == \old(pIp->delaytime)) ==> pIp->delaytime == \old(pIp->delaytime);

*/

void DelayFun(Delay* pIp)

{
    int t = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      loop invariant (0 < \at(pIp,Pre)->delaytime) ==> (t <= \at(pIp,Pre)->delaytime);
      loop invariant (0 < \at(pIp,Pre)->delaytime) ==> (t >= 0);
      loop invariant (!(0 < \at(pIp,Pre)->delaytime)) ==> ((t == 0) && (pIp == \at(pIp,Pre)) && (\at(pIp,Pre)->delaytime == \at(pIp->delaytime,Pre)));
      loop invariant pIp == \at(pIp,Pre);
      loop invariant \at(pIp,Pre)->delaytime == \at(pIp->delaytime,Pre);
    */
    for (; t < pIp->delaytime; t++)
    {
        ;
    }

    return;
}