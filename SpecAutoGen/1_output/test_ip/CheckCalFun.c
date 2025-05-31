
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __CheckCal
{
/* 接口函数 */
/* 输入端口 */
	int				len;
	int 			pkv[3];
	int             chksum;
	/* 输出端口 */
	/* 输入输出端口 */
	/* 状态变量 */
	/* 参数变量 */
} CheckCal;

void CheckCalFun(CheckCal *pIp)

/*@
With pIp_len pIp_pkv_l pIp_pkv_0 pIp_pkv_1 pIp_pkv_2 pIp_chksum
Require pIp->len == pIp_len && store_int_array(pIp->pkv,3, pIp_pkv_l) && pIp_pkv_l[0] == pIp_pkv_0 && pIp_pkv_l[1] == pIp_pkv_1 && pIp_pkv_l[2] == pIp_pkv_2 && pIp->chksum == pIp_chksum
Ensure emp
*/{

	int i;
	int chksum = 0;

	for(i=0; i<pIp -> len; i++)
	{
	    chksum = chksum + pIp -> pkv[i];
	}

	return;
}