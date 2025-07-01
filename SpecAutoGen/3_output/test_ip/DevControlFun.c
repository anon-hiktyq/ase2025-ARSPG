

typedef struct __DevControl
{
  int * p1;
  int * p2;
  int * p3;

} DevControl;

void DevControlFun(DevControl *pIp)
{
	*(pIp->p1)= 0xEB92;

	*(pIp->p2)= 0x01;

	*(pIp->p3)= 0xFC;

	return ;
}