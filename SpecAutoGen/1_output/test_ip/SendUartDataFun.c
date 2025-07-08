
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct __SendUartData
{
/* 输入端口 */
	int			addr;
	int		data[10];
    int         len;
	/* 输出端口 */
	/* 输入输出端口 */
	/* 状态变量 */
	/* 参数变量 */
} SendUartData;

void SendUartDataFun(SendUartData *pIp)

/*@
With pIp_addr pIp_data_l pIp_data_0 pIp_data_1 pIp_data_2 pIp_data_3 pIp_data_4 pIp_data_5 pIp_data_6 pIp_data_7 pIp_data_8 pIp_data_9 pIp_len
Require pIp->addr == pIp_addr && store_int_array(pIp->data,10, pIp_data_l) && pIp_data_l[0] == pIp_data_0 && pIp_data_l[1] == pIp_data_1 && pIp_data_l[2] == pIp_data_2 && pIp_data_l[3] == pIp_data_3 && pIp_data_l[4] == pIp_data_4 && pIp_data_l[5] == pIp_data_5 && pIp_data_l[6] == pIp_data_6 && pIp_data_l[7] == pIp_data_7 && pIp_data_l[8] == pIp_data_8 && pIp_data_l[9] == pIp_data_9 && pIp->len == pIp_len
Ensure emp
*/{
    pIp->len =5;
	int i =0;

	for (; i < pIp -> len; i++)
	{
		pIp -> addr =  pIp -> data[i];
	}
	return;
}