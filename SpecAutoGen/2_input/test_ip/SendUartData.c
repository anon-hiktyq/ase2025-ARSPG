

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
{
    pIp->len =5;
	int i =0;

	for (; i < pIp -> len; i++)
	{
		pIp -> addr =  pIp -> data[i];
	}
	return;
}