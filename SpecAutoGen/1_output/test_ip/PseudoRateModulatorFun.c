
#include "../verification_stdlib.h"
#include "../verification_list.h"
#include "../int_array_def.h"

/*@ Extern Coq (Result: Assertion) */
/*@ Extern Coq (Results: Z -> Assertion) */

    typedef struct TAG_FALSE_RATE_MODULATOR
{
	
	int 	u;					
	int		r;						
	int		Yp;						
	int 	Yn;						
	                            	
}SFratemodulator;
typedef struct __PseudoRateModulator
{
   
    /* 输入端口 */
	int		h1;
	/* 输出端口 */
	/* 输入输出端口 */
	SFratemodulator*     pModulator;
	/* 状态变量 */
	/* 参数变量 */
} PseudoRateModulator;

void PseudoRateModulatorFun(PseudoRateModulator *pIp)

/*@
With pIp_h1 pIp_pModulator_u pIp_pModulator_r pIp_pModulator_Yp pIp_pModulator_Yn
Require pIp->h1 == pIp_h1 && pIp->pModulator->u == pIp_pModulator_u && pIp->pModulator->r == pIp_pModulator_r && pIp->pModulator->Yp == pIp_pModulator_Yp && pIp->pModulator->Yn == pIp_pModulator_Yn
Ensure emp
*/{

	if ((pIp -> pModulator->u - pIp -> pModulator->r) > pIp -> h1)
	{
		pIp -> pModulator->Yp = 0x0 ;
		pIp -> pModulator->Yn = 0xF ;
		pIp -> pModulator->r = 0x0 * pIp -> pModulator->r + 0xF ;
	}
	else if ((pIp -> pModulator->u - pIp -> pModulator->r) < -pIp -> h1)
	{
		pIp -> pModulator->Yp = 0xF ;
		pIp -> pModulator->Yn = 0x0 ;
		pIp -> pModulator->r = 0xF * pIp -> pModulator->r - 0xF ;
	}
	else
	{
		pIp -> pModulator->Yp = 0x0 ;
		pIp -> pModulator->Yn = 0x0 ;
		pIp -> pModulator->r = 0x0 * pIp -> pModulator->r ;
	}

	return ;
}