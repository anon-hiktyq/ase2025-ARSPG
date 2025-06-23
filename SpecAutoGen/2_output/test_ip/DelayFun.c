
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

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

/*@
With pIp_delaytime
Require pIp->delaytime == pIp_delaytime
Ensure (exists t_58, t_58 >= pIp_delaytime && (0 < pIp_delaytime => t_58 <= pIp_delaytime) && (0 < pIp_delaytime => t_58 >= 0) && (!(0 < pIp_delaytime) => t_58 == 0 && pIp == pIp && pIp_delaytime == pIp_delaytime) && pIp->delaytime == pIp_delaytime)
*/
{

    int t=0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((0 < pIp@pre->delaytime) => (t <= pIp@pre->delaytime)) &&
((0 < pIp@pre->delaytime) => (t >= 0)) &&
((!(0 < pIp@pre->delaytime)) => ((t == 0) && (pIp == pIp@pre) && (pIp@pre->delaytime == pIp->delaytime@pre))) &&
(pIp == pIp@pre) &&
(pIp@pre->delaytime == pIp->delaytime@pre)
    */
    
    for (; t < pIp->delaytime; t++)
    {
        ;
    }

    return ;
}