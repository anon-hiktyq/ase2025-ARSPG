
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
/*@
    requires \valid(pIp);
    requires \valid(pIp->data + (0 .. 9));
    ensures pIp->len == 5;
    ensures \forall integer i; 0 <= i < pIp->len ==> pIp->addr == pIp->data[i];
    */
    
void SendUartDataFun(SendUartData *pIp)
{
    pIp->len = 5;
	int i = 0;

	/*@
	  loop invariant (i > 0) ==> (pIp->addr == pIp->data[i-1]);
	  loop invariant (0 < \at(pIp,Pre)->len) ==> (\at(pIp,Pre)->len == 5);
	  loop invariant (0 < \at(pIp,Pre)->len) ==> (\at(pIp,Pre)->addr == pIp->data[i-1]);
	  loop invariant (0 < \at(pIp,Pre)->len) ==> (0 <= i <= \at(pIp,Pre)->len);
	  loop invariant (!(0 < \at(pIp,Pre)->len)) ==> ((i == 0)&&(pIp == \at(pIp,Pre))&&(\at(pIp->addr,Pre) == \at(pIp->addr,Pre))&&(\at(pIp,Pre)->len == 5));
	  loop invariant pIp == \at(pIp,Pre);
	  loop assigns i, pIp->addr;
	  loop variant pIp->len - i;
	*/
	for (; i < pIp->len; i++)
	{
		pIp->addr = pIp->data[i];
	}
	
	return;
}
