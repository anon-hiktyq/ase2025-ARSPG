
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
{

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