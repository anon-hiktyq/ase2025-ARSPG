
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

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

void LimitInt32Fun(LimitInt32 *pIp)

/*@
With pIp_in pIp_bound pIp_value pIp_ret_v pIp_ret
Require pIp->in == pIp_in && pIp->bound == pIp_bound && pIp->value == pIp_value && *(pIp->ret) == pIp_ret_v && (pIp->ret) == pIp_ret
Ensure (pIp_in >= -pIp_bound && pIp_in <= pIp_bound && (pIp->in == pIp_in) * (pIp->bound == pIp_bound) * (pIp->value == pIp_in) * (pIp->ret == pIp_ret) * (*pIp->ret == pIp_in)) || (pIp_in < -pIp_bound && pIp_in <= pIp_bound && (pIp->in == pIp_in) * (pIp->bound == pIp_bound) * (pIp->value == -pIp_bound) * (pIp->ret == pIp_ret) * (*pIp_ret == -pIp_bound)) || (pIp_in > pIp_bound && (pIp->in == pIp_in) * (pIp->bound == pIp_bound) * (pIp->value == pIp_bound) * (pIp->ret == pIp_ret) * (*pIp->ret == pIp_bound))
*/
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